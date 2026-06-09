一般二分查找法

```cpp
class Solution {
public:
    //二分法，因为要找的这个数将数组分割成两半
    //在目标以左（小于这个数）：nums[mid]==nums[mid+1],前提mid必须位于偶数位 
    //在目标以右（大于这个数）：nums[mid]!=nums[mid+1],
    //最后一次low mid high指针指向同一位置，指向目标，high还再往前移动，所以返回low所指
    int singleNonDuplicate(vector<int>& nums) {
        int length=nums.size();
        if(length==1)return nums[0]; 
        int low=0,high=length-1,mid=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(mid%2==1)mid--;
            //如果目标值在最后一位，防止下一步数组溢出，所以直接返回
            if(mid==length-1){
                return nums[mid];
            }
            if(nums[mid]==nums[mid+1]){
                low=mid+2;
            }else{
                high=mid-2;
            }
        }
        return nums[low];
    }
};
```