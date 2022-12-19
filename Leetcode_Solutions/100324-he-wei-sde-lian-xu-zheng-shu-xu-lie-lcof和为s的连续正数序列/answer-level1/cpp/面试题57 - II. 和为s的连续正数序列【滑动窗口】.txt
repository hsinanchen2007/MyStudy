### 解题思路
    设置一个滑动窗口，初始长度为1；
    根据等差数列公式，计算当前窗口的和sum；
    （1）sum > target,说明窗口大了，左边界右移，即i++;
    (2) sum < target,说明窗口小了，右边界右移，即j++;
    (3) sum == target,说明找到了满足条件的一个解，把该窗口对应的值存入数组，左边界右移，继续寻找下一个满足条件的解；
    循环结束条件：窗口长度小于1，即i和j相遇（i==j）

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {

        vector<vector<int>> ans;
        int i = 1,j = 2;
        while(i<j){
            int sum = (i+j)*(j-i+1)/2;
            if(sum > target){ //窗口大了，左边界右移
                i++;
            }else if(sum < target){//窗口小了，右边界右移
                j++;
            }else{
                vector<int> res;
                for(int k=i;k<=j;k++){
                    res.push_back(k);
                }
                ans.push_back(res);
                i++;
            }
        }
        return ans;

    }
};
```