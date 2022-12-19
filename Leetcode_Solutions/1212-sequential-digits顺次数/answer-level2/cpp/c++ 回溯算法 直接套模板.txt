套回溯算法模板，当前数字小于low时继续添加下一位，当前数字大于high时做剪枝。  
<br>

```cpp
class Solution {
public:
    
    void traceBack(int low, int high, int currentNum, int currentTail){
        if(currentNum >= low && currentNum <= high)
            allAns.push_back(currentNum);
        if(currentNum > high)
            return;
        
        if(currentTail + 1 <= 9)
            traceBack(low, high, currentNum*10 + currentTail + 1, currentTail + 1);
    }
    
    vector<int> sequentialDigits(int low, int high) {
        for(int i = 1; i <= 9; i++){
            traceBack(low, high, i, i);
        }
        sort(allAns.begin(), allAns.end());
        return allAns;
    }
    
private:
    vector<int> allAns;  
};
```