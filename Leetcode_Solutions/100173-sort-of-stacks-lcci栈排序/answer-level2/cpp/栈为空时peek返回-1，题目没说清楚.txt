```
class SortedStack {
public:
    stack<int> data,as;
    SortedStack() {
        
    }
    
    void push(int val) {
        while(!data.empty()&&data.top()<val){
            as.push(data.top());
            data.pop();
        }
        data.push(val);
        while(!as.empty()){
            data.push(as.top());
            as.pop();
        }
    }
    
    void pop() {
        if(data.size())
            data.pop();
    }
    
    int peek() {
        if(data.size())
        return data.top();
        return -1;
    }
    
    bool isEmpty() {
        return data.empty();
    }
};
```
