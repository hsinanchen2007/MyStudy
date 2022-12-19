### 解题思路
关键是理解下一个排列是什么意思
不妨将排列看成是一个整数，这些整数由固定数字组成
下一个排列就是找到下一个更大的数

举几个例子可以很快找出规律
如12 3 665544 的下一个排列是
  12 4 345566
从最右边开始遍历数组，找到第一个比右边小的数字
此处是3 将3之后排序 从3之后的下一位遍历 找到第一个比3大的数 交换

大功告成


### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        if (nums.length<=1) return;
        for (int i = nums.length-1,t; i > 0; i--) {
            if (nums[i]>nums[i-1]){
                Arrays.sort(nums,i,nums.length);
                for (int j=i;j<nums.length;j++){
                    if (nums[j]>nums[i-1]){
                        t=nums[j];
                        nums[j]=nums[i-1];
                        nums[i-1]=t;
                        return;
                    }
                }
            }
        }
        Arrays.sort(nums);
    }
}
```