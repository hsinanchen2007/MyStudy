### 解题思路
去重容器，判断个数大小是否相等

### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
      
          Set set = new HashSet(nums.length);
          
          int length = nums.length;
            
          for(int i=0; i<length; i++){
                set.add(nums[i]);
          }

          int size = set.size();

          if(size == length){
              return false;
          }

          return true;
    }
}
```