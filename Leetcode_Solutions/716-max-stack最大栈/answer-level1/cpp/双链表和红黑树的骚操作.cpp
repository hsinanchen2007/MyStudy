### 解题思路

平衡树的key是值，value是双链表指针的列表，切记列表为空的时候在map中抹去该key。

### 代码

```cpp
class MaxStack {
private:
    typedef list<int>::iterator Iter;
    map<int, vector<Iter>> tree;
    list<int> st;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        st.push_front(x);
        tree[x].push_back(st.begin());    // 如果push_back很难得到最后一个元素的iterator，所以用push_front模拟栈
    }
    
    int pop() {
        int x = top();
        st.pop_front();
        tree[x].pop_back();
        if(tree[x].empty())
            tree.erase(x);
        return x;
    }
    
    int top() {
        return st.front();
    }
    
    int peekMax() {
        return tree.rbegin()->first;
    }
    
    int popMax() {
        int x = peekMax();
        auto it = tree[x].back();
        tree[x].pop_back();
        if(tree[x].empty())
            tree.erase(x);
        st.erase(it);
        return x;
    }
};

```

执行用时 :100 ms