### 解题思路

双队列解决！！

### 代码

```cpp
class MaxQueue
{
    queue<int> q;
    deque<int> dq;

public:
    MaxQueue()
    {
    }

    int max_value()
    {
        if (dq.empty())
        {
            return -1;
        }
        else
        {
            return dq.front();
        }
    }

    void push_back(int value)
    {
        q.push(value);

        while (dq.empty() == false && dq.back() < value)
        {
            dq.pop_back();
        }
        dq.push_back(value);
    }

    int pop_front()
    {
        if (!q.empty())
        {
            if (q.front() == dq.front())
            {
                dq.pop_front();
            }
            int tmp = q.front();
            q.pop();
            return tmp;
        }
        return -1;
    }
};
```