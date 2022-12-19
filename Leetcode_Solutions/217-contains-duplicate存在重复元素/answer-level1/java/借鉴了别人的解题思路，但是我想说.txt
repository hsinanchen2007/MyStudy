### 解题思路
借鉴了别人的解题思路，但是我想说，我看了几个java的，完全是借着一些函数方法抄近路，解题来说是最好的，但是并不是实际的依靠自己设计来完成的，我自己也需要多学学这些很少用的函数，也要朝着更原生的代码去解题。

### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
}
```