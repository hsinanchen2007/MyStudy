### 解题思路
遍历每个值为0的点，查询该点前的点能否到达该点即可。
不过坑还挺多的额，最大一个坑是值为0的点在索引0、中间、索引最后是不同的。
执行用时 :12 ms, 在所有 cpp 提交中击败了73.94%的用户
内存消耗 :9.7 MB, 在所有 cpp 提交中击败了90.15%的用户
### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(i==0) return false;
                else if (i==n-1){
                    for(int j=i-1;j>=0;j--){
                        if(nums[j]<i-j){
                            if(j==0) return false;
                            else continue;
                        }
                        else{
                            break;
                        }
                    }
                }
                else{
                    for(int j=i-1;j>=0;j--){
                        if(nums[j]<=i-j){
                            if(j==0) return false;
                            else continue;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        return true;
    }
};
```