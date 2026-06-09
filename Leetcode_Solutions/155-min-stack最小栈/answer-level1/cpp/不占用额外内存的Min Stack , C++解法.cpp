主要思想：在栈的最顶端，一直设置一个存放最小值的空间
pop,push,top组件分别需要配合这个最小值的空间
- pop
    + 每次pop前，需要先pop出最小值，再pop出元素，最后将最小值放回
    + 需要判别pop后，最小值是否需要改变，设计全局int rec, 代表栈中最小值个数，如果rec=0, 需要重新找出最小值
- push
    + 每次push前，需要先pop出最小值，再pop出元素，最后将最小值放回
    + push后，需要比对新元素与当前最小值，判别是否更新最小值
- top
    + top前，需要先pop出最小值，再top，最后将最小值放回
- getMin
    + 仅仅O(1)的时间复杂度，只需要s.top()拿出顶端元素即可。


```C++
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    int rec = 0;
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            s.push(x);
            rec = 1;
        }else{
            int tmp = s.top();
            s.pop();
            s.push(x);
            if(tmp > x){
                s.push(x);
                rec = 1;
            }
            else if (tmp < x){
                s.push(tmp);
            }
            else if (tmp == x){
                s.push(tmp);
                rec++;
            }
        }
    }
    
    void pop() {
        vector<int> arr;
        int tmpmin = s.top();
        s.pop(); // pop min
        int tmpval = s.top();
        s.pop(); // pop val
        if (tmpmin == tmpval)
            rec--;
        if (rec==0){
            tmpmin = INT_MAX;
            while(!s.empty()){
                arr.push_back(s.top());
                tmpmin = min(tmpmin, s.top());
                s.pop();
            }
            for(int i=arr.size()-1;i>=0;i--)
                s.push(arr[i]);
            rec = 1;
        }
        if(!s.empty()){
            s.push(tmpmin);
        }
        
    }
    
    int top() {
        int tmpmin = s.top();
        s.pop();
        int tmp = s.top();
        s.push(tmpmin);
        return tmp;
    }
    
    int getMin() {
        return s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```