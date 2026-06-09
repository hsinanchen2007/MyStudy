### 解题思路
可能麻烦点 但是还算能用
### 代码

```cpp
class MaxQueue {
private:
int maxNum;
int h;
vector<int> R;
public:
    MaxQueue() {
        h = -1;
        maxNum = INT_MIN;
    }
    
    int max_value() {
        if(R.empty()){
            return -1;
        }
        return maxNum;
    }
    
    void push_back(int value) {
        if(value > maxNum) maxNum = value;
        R.push_back(value);
        h += 1;
    }
    
    int pop_front() {
        if(R.empty()){
            return -1;
        }else{
           
            int ret = 0; 
            if(R.size() == 1){
              ret = R[0];
              h -= 1;
              R.pop_back();
              maxNum = INT_MIN;
            }else{
                vector<int> s;
                maxNum = INT_MIN;
                for(int i = 1; i <= h;i++){
                    s.push_back(R[i]);
                    if(maxNum < R[i]){
                        maxNum = R[i];
                    }
                    R.pop_back();
                }
                h -= 1;
                ret = R[0];
                R = s;
            }
            return ret;
        }

    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```