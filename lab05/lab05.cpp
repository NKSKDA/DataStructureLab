#include <iostream>
#include <vector>

using namespace std;

struct BiNode
{
    char data;
    BiNode *lchild;
    BiNode *rchild;
};

// 根据先序序列建立二叉树，字符'0'表示空结点
BiNode *CreateTree(const vector<char> &sequence, int &pos)
{
    if (pos >= sequence.size())
    {
        return nullptr;
    }

    if (sequence[pos] == '0')
    {
        ++pos;
        return nullptr;
    }

    BiNode *root = new BiNode;
    root->data = sequence[pos++];
    root->lchild = CreateTree(sequence, pos);
    root->rchild = CreateTree(sequence, pos);
    return root;
}

// 先序遍历
void PreOrder(BiNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data;
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}

// 中序遍历
void InOrder(BiNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    InOrder(root->lchild);
    cout << root->data;
    InOrder(root->rchild);
}

// 后序遍历
void PostOrder(BiNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    cout << root->data;
}

// 释放二叉树空间
void DestroyTree(BiNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    DestroyTree(root->lchild);
    DestroyTree(root->rchild);
    delete root;
}

int main()
{
    int n;
    cin >> n;

    vector<char> sequence(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> sequence[i];
    }

    int pos = 0;
    BiNode *tree = CreateTree(sequence, pos);

    PreOrder(tree);
    cout << endl;
    InOrder(tree);
    cout << endl;
    PostOrder(tree);
    cout << endl;

    DestroyTree(tree);
    return 0;
}
