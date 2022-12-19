### 解题思路
这是一个比较容易想到的解决方案，把`vector<NestedInteger>`解析成`vector<int>`。

定义一个`vector<int>`和迭代器：

```cpp
vector<int> data;
vector<int>::iterator it;
```

解析：当我们遇到整数时直接往`data`里push，否则递归地调用parse。

```cpp
void parse(const vector<NestedInteger>& nestedList) {
    for (const auto& ni : nestedList) {
        if (ni.isInteger()) data.push_back(ni.getInteger());
        else parse(ni.getList());
    }
}
```

### 代码

```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    vector<int> data;
    vector<int>::iterator it;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        parse(nestedList);
        it = data.begin();
    }
    
    void parse(const vector<NestedInteger>& nestedList) {
        for (const auto& ni : nestedList) {
            if (ni.isInteger()) data.push_back(ni.getInteger());
            else parse(ni.getList());
        }
    }

    int next() {
        return *it++;
    }

    bool hasNext() {
        return it != data.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```