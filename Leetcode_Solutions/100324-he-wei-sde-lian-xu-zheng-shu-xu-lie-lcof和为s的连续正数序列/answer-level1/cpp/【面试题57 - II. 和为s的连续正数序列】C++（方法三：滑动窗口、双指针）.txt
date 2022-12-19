### 解题思路
主要操作：
1. sum<target，扩大窗口，右边界右移（`j++; sum += j;`）
2. sum>target，缩小窗口，左边界右移（`sum -= i; i--;`）
3. sum==target，找到i开头的唯一答案，记录结果，左边界右移（`sum -= i; i--;`）

![image.png](https://pic.leetcode-cn.com/163198a7dd3eb7e751a708545fb90224f9125e211c046a16c3cd285d4797d858-image.png)

### 代码

```cpp
class Solution {
    //滑动窗口（双指针）
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> final_res;
        vector<int> tmp_res;
        if(target<3)
            return final_res;
        int n = (int)target/2;  //窗口左边界最大值
        int i = 1, j = 2;  //窗口左右边界
        int sum; //窗口数字和
        sum = (i+j)*(j-i+1)/2; //初始化等差数列计算窗口和
        while(i<=n){
            while(sum < target){  //sum<target,右窗口j右移
                j++;
                sum += j;
            }
            if(sum>target){  //sum>target,左窗口右移
                sum -= i;
                i++;
            }
            if(sum==target){  //sum=target,记录窗口、插入res
                for(int k = i; k<=j; k++){
                    tmp_res.emplace_back(k);
                }
                final_res.emplace_back(tmp_res);
                tmp_res.clear();
                sum -= i;
                i++;
                // continue;
            }
        }
        return final_res;
        
    }
};
```