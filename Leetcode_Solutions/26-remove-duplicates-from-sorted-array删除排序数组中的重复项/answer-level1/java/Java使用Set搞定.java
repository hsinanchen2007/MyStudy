### 解题思路
利用set不会存储相同元素的性质，设置一个index来修改数组，最后返回Set的长度即为修改后数组的长度。
### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
  Set<Integer> set=new HashSet<>();
       int index=0;
       for (int num:nums
            ) {
           if(set.add(num)){
               nums[i]=num;
               index++;
           }
       }
       return set.size();
    }
}
```