template< class T >
struct BiList {
    T val;
    BiList<T> * next;
    BiList<T> * prev;
};

template< class T>
BiList<T> * create(const T& val)
{
    BiList<T> * node = new BiList<T>{val, nullptr, nullptr};
    node->next = node;
    node->prev = node;
    return node;
}
