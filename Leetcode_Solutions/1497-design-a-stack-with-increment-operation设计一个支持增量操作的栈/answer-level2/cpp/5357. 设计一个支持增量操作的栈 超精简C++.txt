用vector.resize()，不用划很大的数组
![QQ截图20200315124549.png](https://pic.leetcode-cn.com/c0dd0106d73a499605f9625189991756dbe2c87b209d59fb2ec60dbe52fc9125-QQ%E6%88%AA%E5%9B%BE20200315124549.png)

``` c++ []
class CustomStack {
    vector<int> custack; //使用vector是因为他能重载，定义一个超大的数组当然也行
    int max_;
    int top = 0;
public:
    CustomStack(int maxSize) {
        custack.resize(maxSize);
        max_ = maxSize;
    }
    
    void push(int x) {
        if (top >= max_)
            return;
        custack[top++] = x;
    }
    
    int pop() {
        if (top >= 1)
            return custack[--top];
        return -1;
    }
    
    void increment(int k, int val) {
        int n = min(top,k); //k可能会大于栈内元素，所以求一个最小值就行
        for (int i = 0; i < n; i++)
            custack[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
```
