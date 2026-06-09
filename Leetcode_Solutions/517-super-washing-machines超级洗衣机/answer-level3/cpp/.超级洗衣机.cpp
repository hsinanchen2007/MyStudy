### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        int average = 0;
        int res = 0;
        int curSum = 0;
        for(int i=0;i<machines.size();i++){
            sum += machines[i];
        }
        if(sum%machines.size() != 0){
            return -1;
        }

        average = sum / machines.size();
        for(int i=0;i<machines.size();i++){
            machines[i] = machines[i] - average;
            curSum += machines[i];
            res = max(res,abs(curSum));
            res = max(res,machines[i]);
        }

        return res;
    }   

};
```