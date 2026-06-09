```

class Solution
{
public:
    struct Node
    {
        int depth;
        std::array<Node *, 26> childs;
        Node() : depth(0), childs{} {}
        Node(int d) : depth(d), childs{} {}
    };
    void insert(Node *p, const string &w, int i)
    {
        if (i < w.size())
        {
            int x = w[w.size() - 1 - i] - 'a';
            if (p->childs[x] == nullptr)
            {
                p->childs[x] = new Node(i + 1);
            }
            insert(p->childs[x], w, i + 1);
        }
        return;
    }
    int countLeafDepth(Node *p)
    {
        int depth = 0;
        int count = 0;
        queue<Node *> q;
        q.push(p);
        while (!q.empty())
        {
            Node *x = q.front();
            q.pop();
            bool isLeave = true;
            for (int i = 0; i < 26; i++)
            {
                if (x->childs[i] != nullptr)
                {
                    q.push(x->childs[i]);
                    isLeave = false;
                }
            }
            depth += isLeave ? x->depth : 0;
            count += isLeave ? 1 : 0;
        }
        return depth + count;
    }
    int minimumLengthEncoding(vector<string> &words)
    {
        Node *root = new Node;
        for (auto &w : words)
        {
            insert(root, w, 0);
        }
        auto ans = countLeafDepth(root);
        return ans;
    }
};
```
一开始没写数组的构造函数，自己机器上的g++编译器是正常的，提交了就member access within misaligned address，原来指针数组居然没有默认初始化成nullptr