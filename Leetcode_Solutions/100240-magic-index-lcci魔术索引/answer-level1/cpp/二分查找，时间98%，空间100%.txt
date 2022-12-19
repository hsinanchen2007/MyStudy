```
class Solution {
public:
    void findandpush(vector<int>& nums,vector<int>& rec,int left,int right){
        if(left>=right)return;
        int lo = left, hi = right;
        int mid = 0;
        mid = lo + ((hi-lo)>>1);
        if(nums[mid]==mid){
            rec.push_back(mid);
            findandpush(nums,rec,left,mid); //只需要再看前面有没有更小的
        }
        else if(nums[mid]>mid){
            findandpush(nums,rec,nums[mid],right);
            findandpush(nums,rec,left,mid);
        }
        else{
            findandpush(nums,rec,mid+1,right);
            findandpush(nums,rec,left,nums[mid]+1);
        }
    }

    int findMagicIndex(vector<int>& nums) {
        vector<int> ret;
        findandpush(nums,ret,0,nums.size());
        int len = ret.size();
        if(len==0)return -1;
        int min=INT_MAX;
        for(int i=0;i<len;i++){
            min = ret[i]<min?ret[i]:min;
        }
        return min;
    }
};
```
