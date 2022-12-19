### 解题思路
1、先二分查找出target在nums中的位置
2、再从这个位置分别向前和向后找出不等于target的位置

### 代码

```java
class Solution {

    private int findIndex(int[] nums, int target){
        int startIndex = 0;
        int endIndex = nums.length-1;
        int halfIndex = 0;
        while(endIndex>=startIndex){
            halfIndex = startIndex+(endIndex-startIndex)/2;
            if(nums[halfIndex] == target){
                return halfIndex;
            }
            if(halfIndex == startIndex){
                if(nums[startIndex]==target){
                    return startIndex;
                }
                if(nums[endIndex]==target){
                    return endIndex;
                }
                return -1;
            }
            if(nums[halfIndex]>target){
                endIndex = halfIndex;
            }else{
                startIndex = halfIndex;
            }
        }
        return -1;
    }

    public int[] searchRange(int[] nums, int target) {
 //先二分查找target在nums的位置
        if(nums==null || nums.length==0){
            return new int[]{-1,-1};
        }
        int index = findIndex(nums,target);
        if(index==-1){
            return new int[]{-1,-1};
        }
        int i = index;
        int j = index;
        for(;i<nums.length;i++){
            if(nums[i] != target){
                break;
            }
        }
        for(;j>=0;j--){
            if(nums[j] != target){
                break;
            }
        }
        return new int[]{j+1,i-1};
    }
}
```