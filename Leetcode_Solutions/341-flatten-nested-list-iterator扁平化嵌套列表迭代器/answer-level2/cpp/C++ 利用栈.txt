### 解题思路

关键词是“嵌套”，利用栈来模拟深入退出的过程。

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
public:
    stack<vector<NestedInteger>> s;
    stack<int> pos;
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push(nestedList);
        pos.push(0);
    }

    int next() {
        int result = s.top()[pos.top()].getInteger();
        ++pos.top();
        return result;
    }

    bool hasNext() {
        
        while (!pos.empty()) {
            while(pos.top() < s.top().size()) {
                if (!s.top()[pos.top()].isInteger()) {
                    s.push(s.top()[pos.top()].getList());
                    pos.push(0);
                } else {
                    return true;
                }
            }
            while (!pos.empty() && pos.top() >= s.top().size()) {
                pos.pop();
                s.pop();
                if (!pos.empty()) {
                    ++pos.top();
                }
            }
        }
       
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```