方法：
找出最大数及次大数以及最大数的下标，直接进行比较
```
class Solution {
    public int dominantIndex(int[] nums) {
        int index = -1;         //临时存储最大数的下标索引
        int largest = 0;        //临时存储最大的数
        int secondLargest = 0;  //临时存储第二大的数
        for(int i=0; i<nums.length; i++) {
            if(largest <= nums[i]) {
                secondLargest = largest;
                largest = nums[i];
                index = i;
            }else {
                if(secondLargest <= nums[i]) {
                    secondLargest = nums[i];
                }
            }
        }
        if(largest >= 2 * secondLargest) {
            return index;
        }
        return -1;
    }
}
```
