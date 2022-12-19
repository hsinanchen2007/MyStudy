```c++
class StackOfPlates {
public:
    vector<stack<int>>setstack;
    int n;
    StackOfPlates(int cap) {
        n = cap;
    }
    
    void push(int val) {
        if(n>=1){
            stack<int>s;
            s.push(val);
            if(setstack.empty())setstack.push_back(s);
            else{
                if(setstack.back().size()<n)setstack.back().push(val);
                else setstack.push_back(s);
            }
        }
    }
    
    int pop() {
        if(setstack.size() == 0)return -1;
        int a = setstack.back().top();
        setstack.back().pop();
        if(setstack.back().empty())setstack.pop_back();
        return a;
    }
    
    int popAt(int index) {
        if(setstack.empty() || index >= setstack.size())return -1;
        int a = setstack[index].top();
        setstack[index].pop();
        if(setstack[index].empty()){
            auto it = setstack.begin()+index;
            setstack.erase(it);
        }
        return a;
    }
};
```