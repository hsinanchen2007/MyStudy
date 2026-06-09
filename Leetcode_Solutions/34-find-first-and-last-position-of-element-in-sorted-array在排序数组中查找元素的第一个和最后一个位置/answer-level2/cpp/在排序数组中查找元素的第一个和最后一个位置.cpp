左边界lo为数组中小于目标值的元素个数，可能为nums.size()。
右边界hi为数组中小于等于目标值的元素个数再减1,小于等于目标值的元素个数可能为0.

```
class Solution { 
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> a(2);
        a[0] = searchLeft(nums, target);
        a[1] = searchRight(nums, target);
        return a;
    }


    int searchLeft(vector<int>& nums, int target){
        int lo=0,hi=nums.size();  //查找左侧边界
        if(!hi) return -1;
        while(lo<hi){
            int mi = (lo+hi)/2;
            (target<=nums[mi])?hi=mi:lo=mi+1;
        }//lo表示小于target的元素个数
        if(( lo==nums.size() )|| nums[lo]!=target)    //短路求值
            return -1;
        return lo;  
    }
    int searchRight(vector<int>& nums, int target){
        int lo=0,hi=nums.size();  
        if(!hi) return -1;
        while(lo<hi){
            int mi = (lo+hi)/2;
            (target<nums[mi])?hi=mi:lo=mi+1;
        }//lo表示小于等于target的元素个数，lo-1为右侧边界
        if(lo==0) return -1;
        return (nums[lo-1]==target)?lo-1:-1;
    }
};
```
