### 解题思路

思路很简单，遍历往HashSet 中添加元素，根据元素是否添加成功，来判断之前是否已经存储了相同元素。

### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        if(nums == null || nums.length == 1){
            return false;
        }

        HashSet<Integer> hashSet = new HashSet<Integer>();

        for(int i = 0;i< nums.length;i++){
            if(!hashSet.add(nums[i])){//未能成功添加
                return true;
            }
        }

        return false;

    }
}
```