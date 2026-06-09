### 思路
利用栈，因为栈后进先出，所以从后遍历将对象压入栈中。
- next()：获取栈顶元素，返回其整数
- hasNext()：当栈不为空，如果栈顶元素为整数，则直接返回true，否则将弹出的嵌套list中元素从后向前依次压入栈中

### 代码

```cpp
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            st.push(nestedList[i]);
        }
    }

    int next() {
        NestedInteger t = st.top();
        st.pop();
        return t.getInteger();
    }

    bool hasNext() {
        while (!st.empty()) {
            NestedInteger t = st.top();
            if (t.isInteger()) return true;
            st.pop();
            for (int i = t.getList().size() - 1; i >= 0; --i) {
                st.push(t.getList()[i]);
            }
        }
        return false;
    }
private:
    stack<NestedInteger> st;
};
```