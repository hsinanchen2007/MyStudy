### 解题思路
第一步，从前往后遍历，先把0放到数组的最前面。
第二步，从后往前遍历，再把2放到数组的最后面。
始终保持j是寻找0或者2的；i是寻找非0或者非2的。

### 代码

```cpp
class Solution {
public:
    void swap(vector<int> &nums,int i,int j){
        int temp = nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(i<n && j<n){
            while(i<n && nums[i]==0){
                i++;
            }
            j = max(i,j);
            while(j<n &&nums[j]!=0){
                j++;
            }
            if(i<n && j <n){
                swap(nums,i,j);
            }
        }
        i = n-1;
        j = n-1;
        while(i>=0 && j>=0){
            while(i>=0 && nums[i]==2){
                i--;
            }
            j = min(i,j);
            while(j>=0 &&nums[j]!=2){
                j--;
            }
            if(i>=0 && j >=0){
                swap(nums,i,j);
            }
        }
    }
};
```