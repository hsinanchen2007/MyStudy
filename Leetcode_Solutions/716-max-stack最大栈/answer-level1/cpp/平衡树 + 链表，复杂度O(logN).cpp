虽然是easy 但实际上是非常好的一道题目，如果对时间要求更严格，就不能用双栈O(N)来解决了

官方已经提供了这种思路：平衡树中的每一个节点存储一个键值对，其中“键”表示某个在栈中出现的值，“值”为一个列表
但官方只提供了Java的解法，这里提供C++的写法，并充分运用了List的各种函数,可以简洁优雅的完成要求。

```cpp []
class MaxStack {
public:
    /** initialize your data structure here. */
    list<int> l;
    map<int, vector<list<int>::iterator>> mp;

    MaxStack() {
    }

    void push(int x) {
        l.push_front(x);
        mp[x].push_back(l.begin());
    }


    int pop() {
        int key = l.front();
        mp[key].pop_back();
        if(mp[key].empty()) mp.erase(key);
        l.pop_front();
        return key;
    }

    int top() {
        return l.front();
    }

    int peekMax() {
        //rbegin() 返回一个逆序迭代器，它指向容器的最后一个元素
        return mp.rbegin()->first;
    }

    int popMax() {
        int key = mp.rbegin()->first;
        auto it = mp[key].back();
        mp[key].pop_back();
        if(mp[key].empty()) mp.erase(key);
        l.erase(it);
        return key;
    }
};
```
