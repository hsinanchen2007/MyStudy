### 解题思路
1.充分利用条件中的【数字在0-n-1之间】这个特性，将数组下标和数字对应上
### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        //遍历数组nums
        for(int i=0;i<nums.length;i++){
            //如果发现数组下标与数字不一致，则进行互换操作，将数字与下标位置统一起来
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]]){
                    //互换过程中如果发现相同的值，值直接返回      
                    return nums[i];
                }
                //进行交换
                int tmp=nums[i];
                nums[i]=nums[tmp];
                nums[tmp]=tmp;
            }
        }
        return -1;
    }
}
```