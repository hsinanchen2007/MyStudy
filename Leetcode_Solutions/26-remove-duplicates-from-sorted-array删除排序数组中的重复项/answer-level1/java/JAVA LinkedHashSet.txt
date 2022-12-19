### 解题思路
这道题我用的是LinkedHashSet把无重复的元素存入到set集合中，这里强调一点：为什么用LinkedHashSet因为它保证了set集合的顺序而HashSet不保证set的迭代顺序。
这时候set中存入的是nums数组中无重复的数字(并且有序)。
然后把set中的元素赋给nums数组前set.size中，这步操作后最后nums的前set.size就是移除后数组的元素。eg：nums=[0,0,1,1,1,2,2,3,3,4]操作后nums前set.size个元素为nums=[0,1,2,3,4]
### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
         Set<Integer> set = new LinkedHashSet<>();
         for(int i=0;i<nums.length;i++){
             set.add(nums[i]);
         }
         int j = 0;
         for(int i : set){
            nums[j] = i;
            j++;
         }
         return set.size();
    }
}
```