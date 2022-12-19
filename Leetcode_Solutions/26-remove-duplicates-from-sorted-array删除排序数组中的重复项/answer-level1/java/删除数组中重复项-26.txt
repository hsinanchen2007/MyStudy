### 解题思路
![删除数组中重复项-26题.png](https://pic.leetcode-cn.com/aea74831c5b031597a1f1c30832d50771f55220bad3e5c8741e8d93e4415408d-%E5%88%A0%E9%99%A4%E6%95%B0%E7%BB%84%E4%B8%AD%E9%87%8D%E5%A4%8D%E9%A1%B9-26%E9%A2%98.png)


### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int j=0;
        for(int i = 1; i < nums.length; i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;

    }
}
```