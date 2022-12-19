### 解题思路
出现一半以上次数的数字，初始设置count = 0,candidate 为数组的第一个数；
当count = 0的时候，candidate 重新赋值
这题确实需要技巧性的，就这样减下去的话 数组中肯定剩下来的数字就是出现一半次数的数字了。
### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int count  = 0,candidate = 0;
        for(int num:nums){
            if(count==0){
                candidate=num;
            }
            count+=candidate==num?1:-1;
        }
        return candidate;
    }
}
```