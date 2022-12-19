### 解题思路
通过二分查找，找到等于该值的第一个值的位置，同时找到等于该值的最后一个节点的位置；

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums==null||nums.length==0){
            return 0;
        }
        int left = findFirst(nums,target);
        int right = findLarst(nums,target);
        if(left==-1||right==-1){
            return 0;
        }
        return right-left+1;
    }

    public int findFirst(int[] nums,int target){
        int left = 0,right = nums.length-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]<target){
                left = mid+1;
            }else if(nums[mid]>target){
                right = mid-1;
            }else{
                if(mid==0||nums[mid-1]!=target){
                    return mid;
                }else{
                    right = mid-1;
                }
            }
        }
        return -1;
    }
    public int findLarst(int[] nums,int target){
        int left = 0,right = nums.length-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]<target){
                left = mid+1;
            }else if(nums[mid]>target){
                right = mid-1;
            }else{
                if(mid==right||nums[mid+1]!=target){
                    return mid;
                }else{
                    left = mid+1;
                }
            }
        }
        return -1;
    }


}
```