#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>
#include <memory>

template <typename T>
class BinarySearchTree
{
private:
    struct Node
    {
        T data;
        std::shared_ptr<Node> left, right;

        Node(const T &value) : data(value), left(nullptr), right(nullptr) {}
    };

    std::shared_ptr<Node> root;

    void insertHelper(std::shared_ptr<Node> &node, const T &value);
    void inOrderHelper(std::shared_ptr<Node> node) const;
    bool searchHelper(std::shared_ptr<Node> node, const T &value) const;
    std::shared_ptr<Node> deleteHelper(std::shared_ptr<Node> node, const T &value);
    std::shared_ptr<Node> findMin(std::shared_ptr<Node> node) const;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(const T &value);
    void inOrderTraversal() const;
    bool search(const T &value) const;
    void remove(const T &value);
};

// Implementation
template <typename T>
void BinarySearchTree<T>::insert(const T &value)
{
    insertHelper(root, value);
}

template <typename T>
void BinarySearchTree<T>::insertHelper(std::shared_ptr<Node> &node, const T &value)
{
    if (!node)
    {
        node = std::make_shared<Node>(value);
    }
    else if (value < node->data)
    {
        insertHelper(node->left, value);
    }
    else if (value > node->data)
    {
        insertHelper(node->right, value);
    }
}

template <typename T>
void BinarySearchTree<T>::inOrderTraversal() const
{
    inOrderHelper(root);
    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::inOrderHelper(std::shared_ptr<Node> node) const
{
    if (!node)
        return;
    inOrderHelper(node->left);
    std::cout << node->data << " ";
    inOrderHelper(node->right);
}

template <typename T>
bool BinarySearchTree<T>::search(const T &value) const
{
    return searchHelper(root, value);
}

template <typename T>
bool BinarySearchTree<T>::searchHelper(std::shared_ptr<Node> node, const T &value) const
{
    if (!node)
        return false;
    if (value == node->data)
        return true;
    if (value < node->data)
        return searchHelper(node->left, value);
    return searchHelper(node->right, value);
}

template <typename T>
void BinarySearchTree<T>::remove(const T &value)
{
    root = deleteHelper(root, value);
}

template <typename T>
std::shared_ptr<typename BinarySearchTree<T>::Node> BinarySearchTree<T>::deleteHelper(std::shared_ptr<Node> node, const T &value)
{
    if (!node)
        return node;

    if (value < node->data)
    {
        node->left = deleteHelper(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = deleteHelper(node->right, value);
    }
    else
    {
        if (!node->left)
            return node->right;
        if (!node->right)
            return node->left;

        auto minRight = findMin(node->right);
        node->data = minRight->data;
        node->right = deleteHelper(node->right, minRight->data);
    }
    return node;
}

template <typename T>
std::shared_ptr<typename BinarySearchTree<T>::Node> BinarySearchTree<T>::findMin(std::shared_ptr<Node> node) const
{
    while (node && node->left)
    {
        node = node->left;
    }
    return node;
}

#endif
