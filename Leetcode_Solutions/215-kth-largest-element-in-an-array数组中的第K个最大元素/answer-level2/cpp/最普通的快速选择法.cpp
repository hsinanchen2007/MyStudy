### 解题思路
最普通的快速选择法

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums, 0, n-1);
        return nums[n-k];
    }

    void sort(vector<int>& nums, int pre, int end){
        int i=pre, j=end, base=nums[pre];
        if(i >= j){return;}
        while(i < j){
            while(i < j){
                if(nums[j] >= base){j--;}
                else{
                    nums[i]=nums[j];
                    i++;
                    break;
                }
            }    
            while(i < j){
                if(nums[i] <= base) {i++;}
                else{
                    nums[j]=nums[i];
                    j--;
                    break;
                }
            }         
        }
        nums[i] = base;
        sort(nums, pre, i);
        sort(nums, i+1, end);
        return;
    }
};
```