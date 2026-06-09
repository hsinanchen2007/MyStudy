![l.png](https://pic.leetcode-cn.com/628574667b4f008c207850b7876704c84be292749f200fe28ec8c7c5230fbe24-l.png)


### 解题思路
用两个指针分别代表新数组的尾部索引和原数组的遍历索引，过滤重复项，只留递增数字

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums==null|nums.length<1){
            return nums==null?0:nums.length;
        }
        //新数组的尾部索引和原数组的遍历索引
        int p=0,cur=1;
        while(cur<nums.length){
            if(nums[cur]>nums[p]){
                nums[++p]=nums[cur++];
            }else{
                cur++;
            }
        }   
        //多余的空间填充0
        for(int i=p+1;i<nums.length;i++){
            nums[i]=0;
        }
        return p+1;
    }
}
```