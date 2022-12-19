### 解题思路

因为是有序数组，所以可以使用二分查找思想，查看数组中是否存在targe

如果不存在，整个代码结束，并返回0

如果存在，则返回查找到的targe 所在的索引 index ，之后根据 index 往前往后查找是否还存在其他的target。

为什么会往前往后查找呢？因为这是排序的数组，如果存在的话，他们肯定是在一起

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums == null){
            return 0;
        }

        int arrLen = nums.length;
        //出现次数
        int times = 0;

        if(arrLen == 0){
            return times;
        }

        int index = getTargetIndex(nums,target,0,arrLen - 1);
        if(index == -1){
            return times;
        }

        //找到target，因此至少有一个
        times += 1;

        int left = index - 1;
        int right = index + 1;

        while(left >= 0){//往index的左边找
            if(nums[left] == target){
                times ++;
                left --;
            }else {
                break;
            }
        }
    

        while(right < arrLen){
            if(nums[right] == target){
                right ++;
                times ++;
            }else {
                break;
            }
        }

        return times;
    }

    private int getTargetIndex(int[] nums, int target,int start,int end){
        if(start > end){
            return - 1;
        }

        int middle = start + (end - start)/2;

        int middleValue = nums[middle];

        if(middleValue == target){
            return middle;
        }else if(middleValue < target){
            return getTargetIndex(nums,target,middle + 1,end);
        }else {
            return getTargetIndex(nums,target,start,middle - 1);
        }
    }
}
```