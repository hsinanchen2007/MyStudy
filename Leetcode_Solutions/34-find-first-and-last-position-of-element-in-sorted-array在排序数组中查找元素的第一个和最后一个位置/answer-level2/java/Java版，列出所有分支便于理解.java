### 解题思路
两个二分查找分别找到最左和最右的target的值，这里列出了所有的判断，比较好理解

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result={-1,-1};

        if(nums==null||nums.length==0){
            return result;
        }

        result[0]=searchLeft(nums,target);
        result[1]=searchRight(nums,target);

        return result;
    }

    public int searchLeft(int[] nums,int target){
        int left=0;
        int right=nums.length-1;
        int mid=-1;
        //假设right=nums.length-1,left=nums.length-2,此时若是退出，则nums.length-1位置的值就没机会和target比较
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target){
                right=mid-1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else if(nums[mid]<target){
                left=mid+1;
            }
        }

        //实际值比数组的最大值大，则跳出上面的循环时，right=nums.length-1,left=nums.length
        if(right==nums.length-1&&nums[right]!=target){
             return -1;
        }

        //实际值比数组的最小值小，则跳出上面的循环时，right=-1,left=0
        //if(right==-1&&nums[right+1]!=target){
        //    return -1;
        //}

        //跳出循环前的最后一个mid值=right+1
        //if(left>right&&nums[right+1]!=target){
        //    return -1;
        //}

        //合并上面两个注释掉的情况
        return nums[right+1]==target?right+1:-1;
    }

    public int searchRight(int[] nums,int target){
        int left=0;
        int right=nums.length-1;
        int mid=-1;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target){
                left=mid+1;
            }else if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid-1;
            }
        }

        //实际值比数组的最大值大，故跳出上面循环时left=nums.length,right=nums.length-1
        //if(left==nums.length&&nums[left-1]!=target){
        //     return -1;
        //}

        //实际值比数组的最小值小，故跳出上面循环时left=0,right=-1
        if(left==0&&nums[left]!=target){
            return -1;
        }

        //跳出循环前的最后一个mid值=left-1
        //if(left>right&&nums[left-1]!=target){
        //    return -1;
        //}

        //合并上面两个注释掉的情况
        return nums[left-1]==target?left-1:-1;
    }
}
```