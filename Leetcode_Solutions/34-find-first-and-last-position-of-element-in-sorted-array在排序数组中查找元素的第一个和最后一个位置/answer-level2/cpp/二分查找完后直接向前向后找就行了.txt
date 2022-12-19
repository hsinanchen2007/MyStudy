执行结果：
通过
显示详情
执行用时 :
12 ms
, 在所有 C++ 提交中击败了
81.30%
的用户
内存消耗 :
10.2 MB
, 在所有 C++ 提交中击败了
87.12%
的用户


```C++ []
class Solution {
public:
    int binsearch(vector<int>& nums, int left, int right, int target){
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            if(target > nums[mid])
                left = mid + 1;
            else right = mid - 1; 
        }
        return -1; 
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};
        int n = nums.size();
        ans[0] = ans[1] = binsearch(nums, 0, n - 1, target);
        while(ans[0]  > 0 && nums[ans[0] - 1] == target){
            ans[0]--;
        }
        while(ans[1] + 1 > 0 && ans[1]  < n - 1 && nums[ans[1] + 1] == target){
            ans[1]++;
        }
        return ans;
    }
};

```
不管别的，先二分查找找到一个元素，再向前向后一直找就可以了。向前向后的时候注意判别边界，不要数组出界。
## 复杂度
二分查找的复杂度是$O(\log_{2}n)$, 而向前向后查找的复杂度为$O(1)$,因为总的复杂度为$O(\log_{2}n)$