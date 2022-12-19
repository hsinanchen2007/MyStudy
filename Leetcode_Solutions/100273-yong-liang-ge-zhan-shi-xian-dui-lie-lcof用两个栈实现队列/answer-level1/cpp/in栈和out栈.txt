```cpp
class CQueue {
public:
    stack<int> _in,_out;
    bool _flip=false;
    CQueue() {
        
    }
    
    void appendTail(int value) {
        if(!_flip)
        {
            _in.push(value);
        }
        else
        {
            while(_out.empty()==false)
            {
                _in.push(_out.top());
                _out.pop();
            }
            _in.push(value);
            _flip=false;
        }
    }
    
    int deleteHead() {
        if(_flip==false)
        {
            while(_in.empty()==false)
            {
                _out.push(_in.top());
                _in.pop();
            }
            _flip=true;
        }
        int ret=-1;
        if(!_out.empty())
        {
            ret=_out.top();
            _out.pop();
        }
        return ret;
    }
};
```