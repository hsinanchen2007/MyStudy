设区间[i,j)为升序排列的旋转数组，若A[i]<A[j-1]则区间[i,j)为升序，直接返回A[i];
若A[i]>A[j-1]，则区间[i,j)中存在旋转点，继续二分查找[i,(i+j)/2), [(i+j)/2,j)。
特殊的，对于i+1==j，直接返回A[i]。
```
// Time O(lgn), Space O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i=0, k, j=nums.size(); i<j;){
            if(i+1==j || nums[i]<nums[j-1]) return nums[i];
            k=(i+j)/2;
            if(i+1<k && nums[i]>nums[k-1]) j=k;
            else i=k;
        }
        return 0;
    }
};
```
