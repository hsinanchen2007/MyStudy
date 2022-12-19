### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int key=BioSearch(nums, target);
        if(key==-1){
            return 0;
        }
        int count=1;
        int start=key-1;
        int end=key+1;
        while(start>=0&&nums[start--]==target){
            count++;
        }
        while(end<=(nums.size()-1)&&nums[end++]==target){
            count++;
        }
        return count;
    }
    int BioSearch(vector<int>& nums, int target){
        int left=0;
        int right=nums.size()-1 ;
        int mid=0;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        } 
        return -1;
    }
};
```