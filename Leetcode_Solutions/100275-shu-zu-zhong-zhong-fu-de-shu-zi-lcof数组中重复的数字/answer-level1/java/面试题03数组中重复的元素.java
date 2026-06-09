### 解题思路
由于题目规定，所有数字都在0-n-1的范围内，所以如果没有重复的话，那么每个元素都能与其下标相对应。
例如，n=5，那么数组经过调整后，必然能够出现{0,1,2,3,4}的情况。
按照这个思路，我们可以遍历这个数组，如果当前元素与其下标不相等的话，那么就swap(nums[i],nums[nums[i]])，此时，nums[i]位置上的元素与下标值相等。
如果nums[i]和nums[nums[i]]相等的话，说明该元素为重复元素，返回即可。
时间复杂度O(N),空间复杂度O(1)

### 代码

```java
class Solution {
        public int findRepeatNumber(int[] nums) {
        for (int i=0;i<nums.length;i++){
            while (nums[i]!=i){
                if (nums[i]!=nums[nums[i]]){
                    swap(nums,nums[i],nums[nums[i]]);
                }else {
                    return nums[i];
                }
            }
        }
        return -1;
    }
    public void swap(int[] nums,int index1,int index2){
        int temp=nums[index1];
        nums[index1]=nums[index2];
        nums[index2]=temp;
    }
}
```