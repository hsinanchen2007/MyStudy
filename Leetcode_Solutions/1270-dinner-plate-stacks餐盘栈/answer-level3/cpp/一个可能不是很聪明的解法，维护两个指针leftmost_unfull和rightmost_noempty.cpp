### 解题思路
即维护两个指针，leftmost_unfull和rightmost_noempty,每次操作的时候都更新这两个指针。

### 代码

```cpp
class DinnerPlates {
private:
    vector<stack<int>> stk;
    int _capacity;
    int leftmost_unfull;
    int rightmost_noempty;

public:
    DinnerPlates(int capacity) {
        this->_capacity = capacity;
        stk.push_back(stack<int>());
        leftmost_unfull = 0;
        rightmost_noempty = -1;
    }

    void push(int val) {
        stk[leftmost_unfull].push(val);
        if(rightmost_noempty < leftmost_unfull){
            rightmost_noempty = leftmost_unfull;
        }
        if(stk[leftmost_unfull].size() == this->_capacity) {
            while (++leftmost_unfull < stk.size()) {
                if (stk[leftmost_unfull].size() < this->_capacity) break;
            }
            if (leftmost_unfull == stk.size()) {
                stk.push_back(stack<int>());
            }
        }
        // cout << "end push" << val << ": leftmost_unfull = " << leftmost_unfull << ", rightmost_noempty = " << rightmost_noempty << endl;
    }

    int pop() {
        if(rightmost_noempty == -1) return -1;
        int val = stk[rightmost_noempty].top();
        stk[rightmost_noempty].pop();
        if(rightmost_noempty < leftmost_unfull){
            leftmost_unfull = rightmost_noempty;
        }
        if(stk[rightmost_noempty].empty()){
            while(--rightmost_noempty >= 0){
                if(!stk[rightmost_noempty].empty()) break;
            }
        }
        // cout << "end pop" << ": leftmost_unfull = " << leftmost_unfull << ", rightmost_noempty = " << rightmost_noempty << endl;
        return val;
    }

    int popAtStack(int index) {
        if(index >= stk.size() || stk[index].empty()) return -1;
        int val = stk[index].top();
        stk[index].pop();
        if (index < leftmost_unfull) leftmost_unfull = index;
        if (rightmost_noempty == index && stk[index].empty()){
            while(--rightmost_noempty >= 0){
                if (!stk[rightmost_noempty].empty()) break;
            }
        }
        // cout << "end popAtStack " << index << ": leftmost_unfull = " << leftmost_unfull << ", rightmost_noempty = " << rightmost_noempty << endl;
        return val;
    }
};
```