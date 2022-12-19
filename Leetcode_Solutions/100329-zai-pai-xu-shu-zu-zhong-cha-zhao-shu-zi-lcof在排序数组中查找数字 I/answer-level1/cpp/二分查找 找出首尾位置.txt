```
class Solution {
public:
    int getFirst(vector<int>& nums,int start,int end,int target){
        if(start>end) return -1;
        int mid=start+(end-start)/2;
        if(nums[mid]==target){
            if((mid>0&&nums[mid-1]!=target)||mid==0){
                return mid;
            }
            else{
                end=mid-1;
            }
        }
        else if(nums[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        return getFirst(nums,start,end,target);
    }
    int getLast(vector<int>& nums,int start,int end,int target){
        if(start>end) return -1;
        int mid=start+(end-start)/2;
        if(nums[mid]==target){
            if((mid==nums.size()-1)||mid<nums.size()-1&&nums[mid+1]!=target){
                return mid;
            }
            else start=mid+1;
        }
        else if(nums[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        return getLast(nums,start,end,target);
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        if(nums.size()==1){
            if(nums[0]==target) return 1;
            else return 0;
        }
        int left=getFirst(nums,0,nums.size()-1,target);
        int right=getLast(nums,0,nums.size()-1,target);
        if(left==-1||right==-1) return 0;
        if(right-left>=0) return right-left+1;
        else return 0;
    }
};
```
