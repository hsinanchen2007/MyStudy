### 解题思路
每个栈的最大规模 size 已经确定。
给数组分配 3 * (size + 1) 个空间。
第 i 个栈现已有的元素个数记录在数组的第 i * (size + 1) 个元素中，其中 i = 0, 1, 2。

### 代码
```
class TripleInOne {
    int size;
    vector<int> vec;
public:
    TripleInOne(int stackSize) {
        size = stackSize;
        vec.assign(3 * (size + 1), 0);
    }
    
    void push(int stackNum, int value) {
        int start = stackNum * (size + 1);
        if(vec[start] < size)
        {
            int i = vec[start];
            vec[start] = i + 1;
            vec[start + i + 1] = value;
        }
    }
    
    int pop(int stackNum) {
        int start = stackNum * (size + 1);
        if(vec[start] > 0)
        {
            int i = vec[start];
            vec[start] = i - 1;
            return vec[start + i];
        }
        return -1;
    }
    
    int peek(int stackNum) {
        int start = stackNum * (size + 1);
        if(vec[start] == 0)
        {
            return -1;
        }
        int i = vec[start];
        return vec[start + i];
    }
    
    bool isEmpty(int stackNum) {
        int start = stackNum * (size + 1);
        if(vec[start] == 0)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
```
