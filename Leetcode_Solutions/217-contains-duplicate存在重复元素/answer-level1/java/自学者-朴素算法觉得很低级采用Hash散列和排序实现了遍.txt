### 解题思路
* 朴素迭代检索觉得太低级，没用来编辑
* 先采用Hash散列实现了一遍，又觉得太投机取巧
* 最后排序，根据相等挨着这条规则实现

最高兴三种思路脑袋里都有。

### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
         Arrays.sort(nums);
        for(int i = 0; i < nums.length-1; i++) {
            if(nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
}
```