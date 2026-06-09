
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1,mid=0;
        if(nums.size()==0)
        {
        	return -1;
        }

        while(start<end){
            mid=start+(end-start)/2;
            //cout<<"start:"<<start<<" mid:"<<mid<<" end:"<<end<<endl;
        	if(nums[mid]==target)
	        {
	        	return mid;
	        }

	        if(nums[mid]>=nums[start])//左边有序
	        {
	        	if(target<nums[mid]&&target>=nums[start]){//在左边
	        		end=mid-1;    	
	        	}else{//在右边
	        		start=mid+1;
	        	}
	        }else//右边有序
	        {
	        	if(target>nums[mid]&&target<=nums[end]){//在右边
	        		start=mid+1;
	        	}else{//在左边
	        		end=mid-1;
	        	}
	        }
        }
        //cout<<"start:"<<start<<" end:"<<end<<endl;
        return start<nums.size()?(nums[start]==target?start:-1):-1;
    }
};
```
