### 解题思路
整体的思路：
1.首先从一个旋转的数组确定target在哪一半部分，比较target、nums第一个元素、nums中间值，
2.然后继续递归调用，根据特殊情况可能会取两个部分的值，因为根据nums第一个元素和中间值也没有办法完全确定是哪个部分，例如[1,3,1,1,1]
代码量应该有优化的空间。

### 代码

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return false;
        return helper(nums, target, 0, n-1);
    }
    bool helper(vector<int>& nums,int target,int i,int j){
        if(i>j) return false;
        if(i==j){
            if(nums[i]==target) return true;
            else return false;
        }
        int m = (i+j)/2;
        if(target<nums[i]){
            if(target>nums[j]) return false;
            if(nums[m]>=nums[i]){
                return helper(nums, target, m+1, j)||helper(nums, target, i, m-1);
            }
            else{
                if(target>nums[m]){
                    i = m+1;
                    while(i<=j){
                        int x = (i+j)/2;
                        if(nums[x]>target){
                            j = x-1;
                        }
                        else if (nums[x]<target){
                            i = x+1;
                        }
                        else{
                            return true;
                        }
                    }
                    return false;
                }
                else if (target<nums[m]){
                    return helper(nums, target, i, m-1);
                }
                else{
                    return true;
                }
            }
        }
        else if(target==nums[i]) return true;
        else {
            if(nums[m]>=nums[i]){
                if(target>nums[m]){
                    return helper(nums, target, m+1, j)||helper(nums, target, i, m-1);
                }
                else if (target==nums[m]){
                    return true;
                }
                else {
                    j = m-1;
                    while(i<=j){
                        int x = (i+j)/2;
                        if(nums[x]>target){
                            j = x-1;
                        }
                        else if(nums[x]==target){
                            return true;
                        }
                        else {
                            i = x+1;
                        }
                    }
                    return false;
                }
            }
            else{
                return helper(nums, target, i, m-1);
            }
        }
    }
};

```