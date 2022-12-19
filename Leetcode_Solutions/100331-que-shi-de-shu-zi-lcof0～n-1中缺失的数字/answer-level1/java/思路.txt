### 解题思路
此处撰写解题思路
我的思路:
    通过数组的下标和值对比，如果当前下标和值不一样的话就直接返回当前下标
如果能循环结束那就说明都是有序的，只能返回数组的长度了；
### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        for(int i=0;i<nums.length;i++){
           if(nums[i]!=i){
            return i;
           }
        }
        return nums.length;
        
    }
}
```