***Talk is cheap. Show me the code.***

![Xnip2020-03-20_18-57-20.jpg](https://pic.leetcode-cn.com/d21a12157ce0bb250298c51aef69614cc21eb61bff11c2fb97a6078943fd0091-Xnip2020-03-20_18-57-20.jpg)

递归：
```
class NestedIterator {
    typedef vector<NestedInteger>::const_reverse_iterator iterator_type;

private:
    stack<iterator_type> stk;

public:
    NestedIterator(vector<NestedInteger>& nestedList)
    {
        flatten(nestedList);
    }

    void flatten(const vector<NestedInteger>& nestedList)
    {
        for (auto it = nestedList.crbegin(); it != nestedList.crend();
             ++it) {
            if (it->isInteger()) {
                stk.push(it);
            } else {
                flatten(it->getList());
            }
        }
    }

    int next()
    {
        int data = stk.top()->getInteger();
        stk.pop();
        return data;
    }

    bool hasNext()
    {
        return !stk.empty();
    }
};
```

迭代、栈：
```cpp
class NestedIterator {
    typedef vector<NestedInteger>::const_reverse_iterator iterator_type;

private:
    stack<iterator_type> stk;

public:
    NestedIterator(vector<NestedInteger>& nestedList)
    {
        stack<pair<iterator_type, iterator_type>> tmp;
        tmp.push({nestedList.crbegin(), nestedList.crend()});
        while (!tmp.empty()) {
            auto&& top = tmp.top();
            iterator_type iter = top.first;
            iterator_type end = top.second;
            tmp.pop();
            while (iter != end) {
                if (iter->isInteger()) {
                    stk.push(iter);
                    iter++;
                } else {
                    tmp.push({iter + 1, end});
                    end = iter->getList().crend();
                    iter = iter->getList().crbegin();
                }
            }
        }
    }

    int next()
    {
        int res = stk.top()->getInteger();
        stk.pop();
        return res;
    }

    bool hasNext()
    {
        return !stk.empty();
    }
};

```

