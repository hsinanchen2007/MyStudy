思路：

这道题做法比较多，这里用一个 map 来记录下标和 stack 的关联关系，再用一个 set 来维护可用的位置，因为 map 和 set 都是有序的，所以每次 push 时往 set 的第一个元素 push 即可， pop 则对 map 的最后一个元素 pop 出来同时更新 set 里的可用位置

代码实现：

```c++
class DinnerPlates {
    int _capacity;
    map<int, vector<int>> _data;
    set<int> _avaliable;
public:
    DinnerPlates(int capacity) {
        _capacity = capacity;
    }
    
    void push(int val) {
        if (_avaliable.empty()) {
            _avaliable.insert(_data.size());
        }
        int pos = *_avaliable.begin();
        _data[pos].push_back(val);
        
        if (_data[pos].size() == _capacity) {
            _avaliable.erase(pos);
        }
    }
    
    int pop() {
        if (_data.size() == 0) return -1;
        int val = _data.rbegin()->second.back();
        _data.rbegin()->second.pop_back();
        _avaliable.insert(_data.rbegin()->first);
        if (_data.rbegin()->second.size() == 0) {
            _data.erase(_data.rbegin()->first);
        }
        return val;
    }
    
    int popAtStack(int index) {
        if (_data.find(index) == _data.end() || _data[index].size() == 0) return -1;
        int val = _data[index].back();
        _data[index].pop_back();
        _avaliable.insert(index);
        if (_data[index].size() == 0)
            _data.erase(index);
        return val;

    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
```

更多题解欢迎关注 [Do Leetcode For Fun](https://zhuanlan.zhihu.com/c_1145647496591298560) 专栏~