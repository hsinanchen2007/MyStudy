
c++  99%  使用数组模拟队列  因为这个操作次数是有限的   所以没有清除出队后的空间   

- 入队  取最大值都为O(1)
- 出队时  需要判断是否 取出最大值，且队列中最大值只有一个   如果取出最大值，则需要更新最大值   否则直接出队  

均摊复杂度应该全部为O(1)？  有没有大佬判断一下 满足题意？

```
class MaxQueue {
private:
    vector<int> dp;
    int maxval = INT_MIN;
    int index = 0;
    int cnt = 0;
public:
    MaxQueue() {
        
    }
    
    int max_value() {
        if(index >= dp.size()) return -1;
        else return maxval;
    }
    
    void push_back(int value) {
        dp.push_back(value);
        if(value>maxval){
            maxval = value;
            cnt = 1;
        }else if(value == maxval) cnt+=1;
    }
    
    int pop_front() {
        if(index >= dp.size() ) return -1;
        int value = dp[index];
        index += 1;

        if(value == maxval){
            if(cnt>1) cnt--;
            else {
                maxval = INT_MIN;
                for(int i=index;i<dp.size();i++)
                    maxval = max(maxval,dp[i]);
                cnt = 1;
            }
        }
        
        return value;
    }
};
```

