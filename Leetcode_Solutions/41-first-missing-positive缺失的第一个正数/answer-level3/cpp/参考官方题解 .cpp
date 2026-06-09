### 解题思路
参考官方题解进行

### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // if(len<1) return 1;
        bool findone = false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){findone=true;}
            if((nums[i]<=1)||(nums[i]>n)){nums[i]=1;}
        }
        if(!findone) return 1;
        for(int i=0;i<n;i++){
            if(abs(nums[i])<n){
                nums[abs(nums[i])] = -abs(nums[abs(nums[i])]);// 代表该位置的值出现过
            }
            else nums[0] = -abs(nums[0]);
        }
        // bool find = fa
        for(int i=1;i<n;i++){
            if(nums[i]>0) return i;
        }
        // cout<<nums[0]<<endl;
        if(nums[0]>0) return n;
        return n+1;
    }
};
```