### 总体思路
1. 先排序。
2. 确定最左边的数，然后再在剩下的数中找两数之和与之相反。方法是在该数的右边的有序数列中，用两个端点处的指针向中间扫描。就是在剩余的排序数组的两数之和问题O(n)。
3. 每个数都可能是最左边的数。所以总体复杂度为n平方。

### 难点在于去重复
由于是排序的，如果两个三元组的第一个数不同，那么这两个三元组一定不同。我们就是要找出以每一种数开头的所有可行的三元组。比如说输入数组有-1，-2，-2，-1，-4,0，2,1  这,8个数，但是不同的数的种类只有6种，我们就在排序后，让每个种类的数有且仅有一次机会尝试成为三元组的第一个数。方法是每次遍历到第一个数的时候，判断这个数是否和上一个数相等，如果相等，那么说明在之前肯定以这个数为第一个数考虑过了。 也就是说让每一个三元组的第一个数都是与之前不同的数。

另一方面，在确定剩下的两个元素的时候，也要注意去除重复，当扫描到一组可行解的时候，要让左右指针继续扫描到下一个与之前的数不等的位置。当然前提是两个指针没有相遇。


```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        sort(nums.begin(), nums.end()); 
        int i = 0;
        while(i<nums.size()-2){
            if(nums[i]>0) break;
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                if(nums[i]+nums[left]+nums[right] == 0){
                    vector<int> t{nums[i],nums[left],nums[right]};
                    res.push_back(t);
                    while(left+1<right && nums[left+1]==nums[left]){
                        left++;
                    } 
                    left++;
                    while(left<right-1 && nums[right-1] == nums[right]){
                        right--;
                    } 
                    right--;
                }else if(nums[i]+nums[left]+nums[right] > 0){
                    right--;
                }else{
                    left++;
                }
            }
            while(i+1<nums.size()-2 && nums[i+1] == nums[i]){
                i++;
            }
            i++;
        }
        return res;
    }
};
```
