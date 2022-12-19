栈a进入，栈b出队列
![QQ图片20200214221236.png](https://pic.leetcode-cn.com/62c057fa9120ce9cbe6295302097bc5f3357a1e60f3bf9ddcd8c56d04b015e28-QQ%E5%9B%BE%E7%89%8720200214221236.png)
进行入队时，压入栈a
出队是，先检查栈a,b是否为空
1.a,b均为空，返回-1
2.b非空，返回b栈顶
3.a非空，b空，将栈a中元素全部压入栈b
```
class CQueue {
public:
    stack<int> a;
    stack<int> b;
    CQueue() {

    }

    void appendTail(int value) {
        a.push(value);
    }

    int deleteHead() {
        if (b.empty() && a.empty())
            return -1;
        else if (b.empty() && !a.empty())
        {
            while (!a.empty())
            {
                b.push(a.top());
                a.pop();
            }
        }
        int temp = b.top();
         b.pop();
        return temp;     
    }
};

```
