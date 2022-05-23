#pragma once
#include <iostream>

template <typename T>
class List
{
    struct Node
    {
        Node() : m_next(nullptr) { }
        Node(const T& t) : m_t(t), m_next(nullptr) { }
        T m_t; // Значение узла
        Node* m_next; // Указатель на следующий узел
    };
    Node* m_head; // Голова односвязного списка

    class Iterator
    {
        Node* m_node;
    public:
        Iterator(Node* node) : m_node(node) { }

        // Проверка на равенство
        bool operator==(const Iterator& other) const
        {
            if (this == &other) return true;
            return m_node == other.m_node;
        }

        // Проверка на неравенство
        bool operator!=(const Iterator& other) const { return !operator==(other); }

        // Получение значения текущего узла
        T& operator*() const { return m_node->m_t; }

        // Переход к следующему узлу
        void operator++() { if (m_node)  m_node = m_node->m_next; }

        //Слияние очередей
        Iterator operator+(std::size_t n)
        {
            Iterator result(m_node);
            for (; n != 0; --n) { ++result; }
            return result;
        }
    };

public:
    List() : m_head(nullptr) { }
    ~List() { while (m_head) { remove(); } }

    void append(const T& t)
    {
        if (Node* node = new Node(t))
        {
            node->m_next = m_head; //Новый узел привязывается к старому головному элементу
            m_head = node; //Новый узел сам становится головным элементом
        }
    }

    void remove()
    {
        if (m_head) //Если список не пуст:
        {
            Node* newHead = m_head->m_next; // Сохраняем указатель на второй узел, который станет новым головным элементом
            delete m_head; // Освобождаем память, выделенную для удаляемого головного элемента
            m_head = newHead; // Назначаем новый головной элемент
        }
    }

    // Получить головной элемент списка
    T head() const { return m_head->m_t; }

    // Получить итератор на начало списка
    Iterator begin() const { return Iterator(m_head); }

    // Получить итератор на конец списка
    Iterator end() const { return Iterator(nullptr); }

    std::size_t size() const
    {
        size_t s = 0;
        for (Iterator it = begin(); it != end(); ++it) ++s;
        return s;
    }

    T& operator[](std::size_t i) { return *(begin() + i); }

};

template<typename T>
List<T>& operator+=(List<T>& a, const List<T>& b)
{
    for (auto i = b.begin(); i != b.end(); ++i) { a.append(*i); }
    return a;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& list)
{
    for (auto i = list.begin(); i != list.end(); ++i) { out << *i << " "; }
    return out;

}
