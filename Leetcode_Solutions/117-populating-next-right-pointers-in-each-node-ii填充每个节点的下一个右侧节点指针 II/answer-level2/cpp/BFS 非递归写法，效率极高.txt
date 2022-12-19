
![image.png](https://pic.leetcode-cn.com/23d9fb5030ca5a8e9145ab65a632ea015f5ff785f44526e378faa89f640eeb8d-image.png)

```c++ []
Node *connect(Node *root)
    {
        //117. Populating Next Right Pointers in Each Node II
        //bfs
        if (root == nullptr)
            return nullptr;
        queue<Node *> myque;
        myque.push(root);
        while (!myque.empty())
        {
            int size = myque.size();
            for (int i = 0; i < size; ++i)
            {
                Node *temp = myque.front();
                myque.pop();
                if (!myque.empty() && i != size - 1)
                    temp->next = myque.front();
                if (temp->left != nullptr)
                    myque.push(temp->left);
                if (temp->right != nullptr)
                    myque.push(temp->right);
            }
        }
        return root;
    }
```


