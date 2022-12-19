### 解题思路
就按照题意去写，内部容器用vector模拟，利用push_back和pop_back来达到LIFO的效果

### 代码

```cpp
class CustomStack {
private:
    int maxStackSize;
    vector<int> stk;
public:
    CustomStack(int maxSize) {
        maxStackSize = maxSize;
    }
    
    void push(int x) {
        if (stk.size() < maxStackSize) {
            stk.push_back(x);//加到队尾
        }
    }
    
    int pop() {
        int res = 0;
        if (stk.size() != 0) {
            res = stk.back();//取最后加入的元素
            stk.pop_back();//弹出最后加入的元素
        } else {
            res = -1;
        }

        return res;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k && i < stk.size(); ++i) {//从队头(栈底)开始加注意边界
            stk[i] += val;
        }
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