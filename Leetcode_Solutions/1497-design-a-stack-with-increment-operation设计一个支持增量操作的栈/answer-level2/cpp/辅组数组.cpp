```c++
class CustomStack {
public:
    CustomStack(int maxSize) {
        this->capbility = maxSize;
        this->add = vector<int>(1001,0);
    }
    
    void push(int x) {
        if(s.size() >= this->capbility) return;
        s.push(x);
    }
    
    int pop() {
        if(s.empty()) return -1;
        int sz = s.size();
        int curr = s.top() + add[sz];
        add[sz-1] += add[sz];
        add[sz] = 0;
        s.pop();
        return curr;
    }
    
    void increment(int k, int val) {
        if(s.empty()) return;
        if(k > s.size()){
            add[s.size()] += val;
        }else{
            add[k] += val;
        }
    }
private:
    int capbility;
    stack<int> s;
    vector<int> add;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
```