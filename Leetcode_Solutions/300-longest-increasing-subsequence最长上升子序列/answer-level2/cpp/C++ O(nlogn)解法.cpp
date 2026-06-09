### 解题思路
利用patience sort排序。
如果发现更大的值，直接增加堆数；否则更新刚好大于新值的堆顶。
### 代码

```cpp
class Solution {
public:
    int lowerBound(const vector<int>& nums, int value){
        int left = 0;
        int right = nums.size();
        while(left<right){
            int mid = left + (right-left)/2;
            if(nums[mid] == value){
                right = mid;
            }else if(nums[mid]>value){
                right = mid;
            }else {
                left = mid+1;
            }
        }

        return right;
    }
    int lengthOfLIS(vector<int>& nums) {
            if(nums.empty()){
                return 0;
            }
            vector<int> seq;
            seq.push_back(nums[0]);
            for(int i=1; i<nums.size();i++){
                 if(nums[i]>seq.back()){
                     seq.push_back(nums[i]);
                 }else{
                     int index = lowerBound(seq, nums[i]);
                     seq[index] = nums[i];
                 }
                
            }

            return seq.size();
    }
};
```