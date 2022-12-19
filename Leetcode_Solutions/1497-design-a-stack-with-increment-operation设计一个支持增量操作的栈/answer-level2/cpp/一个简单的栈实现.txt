### 解题思路
一个简单的数组加指针的内部数据结构的实现

### 代码

```cpp

class CustomStack {
public:
    CustomStack(int maxSize) {
        _size = maxSize;
        _flag = 0;
        _stack_ptr = new int[maxSize];
    }
    ~CustomStack(){
        delete [] _stack_ptr;
    }
    
    void push(int x) {
        if(_flag < _size){
            _stack_ptr[_flag] = x;
            _flag = _flag + 1;
        }
    }
    
    int pop() {
        if(_flag == 0){
            return -1;
        }
        else{
            _flag = _flag - 1;
            return _stack_ptr[_flag];
        }
    }
    
    void increment(int k, int val) {
        int kv = k<_flag?k:_flag;
        for(int i = 0; i < kv; ++i){
            _stack_ptr[i] = _stack_ptr[i] + val;
        }
    }
private:
    int _size;
    int _flag;
    int *_stack_ptr;
    CustomStack(){}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
```