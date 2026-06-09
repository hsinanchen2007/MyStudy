### 解题思路
此处撰写解题思路
我的思路:
    同过遍历，用当前的值和后面的一个值进行比较，如果相同的话，说明这个值就是个重复的，那么就直接返回这个数组的元素
如果不是，那就直接返回0；
### 代码

```java
class Solution {
    public int findDuplicate(int[] nums) {
        int len=0;
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                if(nums[i]==nums[j]){
                    return nums[i];
                }
            }
        }
        return len;
    }
}
```