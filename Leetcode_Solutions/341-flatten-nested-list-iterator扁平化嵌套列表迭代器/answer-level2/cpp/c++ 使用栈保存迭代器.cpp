解题思路：用栈保存各层迭代的当前迭代器和结束迭代器

```
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push({nestedList.cbegin(), nestedList.cend()});
    }

    int next() {
       int val = s.top().first->getInteger();
       ++s.top().first;

        return val;
    }

    bool hasNext() {
        while (!s.empty()) {
            if (s.top().first == s.top().second) {
                s.pop();
                continue;
            }
            if (!s.top().first->isInteger()) {
                const auto& list = s.top().first->getList();
                ++s.top().first;
                s.push({list.cbegin(), list.cend()});
            } else {
                break;
            }
        }

        return !s.empty();
    }

private:
    using Iterator = vector<NestedInteger>::const_iterator;
    stack<std::pair<Iterator, Iterator>> s;
};
```
