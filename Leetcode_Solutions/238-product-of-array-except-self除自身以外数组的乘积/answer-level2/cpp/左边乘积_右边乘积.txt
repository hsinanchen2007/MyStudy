### 解题思路
1、先通过两次循环得到L、R两个关于nums[i]左右两边乘积的数组，L[i]=nums[i]*L[i-1],R[i] = nums[i+1]*R[i+1],
2、结果输出L[i]*R[i]。
注意：对于L，R两个循环起始边界边界的设置L[0]=R[len-1]=1

### 代码

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int L[len],R[len];
        L[0]=1;R[len-1]=1;
        for(int i = 1 ; i<len ; i++){
            L[i] = nums[i-1]*L[i-1];
        }
        for (int j = len-2 ; j >= 0 ; j--){
            R[j]= nums[j+1]*R[j+1];
        }
        for(int i = 0 ; i<len ; i++){
            nums[i] = L[i]*R[i];
        }
        return nums;  
    }
};
```