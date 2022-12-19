### 解题思路
先创建一个等大哈希表，将原数组按照顺序依次判断哈希表中是否已经有了该数字，如果已经有了就找到重复数字，没有的话就放入哈希表中（+1）。该法时间复杂的为O（n），空间因为创建哈希所以也是O(n)。

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
           int[] arr =new int[nums.length];
           for(int i=0;i<nums.length;i++){
               arr[nums[i]]++;
               if(arr[nums[i]]>1)return nums[i];
           }
           return -1;
    }
}
```