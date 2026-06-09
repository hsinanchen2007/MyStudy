### 解题思路
两边总有一遍是有序的；每次判断一下有序的那边有没有target，有的话就从里面找；没有就从另一半找

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int mid=left + (right-left)/2;
        while(left<=right){
            mid=left + (right-left)/2;
            if(nums[mid]==target) return mid;

            if(nums[left] <= nums[mid]){  //左边升序
                if(target >= nums[left] && target <= nums[mid]){//在左边范围内
                    right = mid-1;
                }else{//只能从右边找
                    left = mid+1;
                }
            }else{ //右边升序
                if(target >= nums[mid] && target <= nums[right]){//在右边范围内
                    left = mid +1;
                }else{//只能从左边找
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};
```