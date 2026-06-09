### 解题思路
方法一：使用hashset保存nums中的所有数，再从1开始遍历到n，找到set中不存在的key，额外使用set的空间
方法二：改变nums[i]-1索引处对应的值；
        如果k缺失，则k-1处的值可以与其他位置的值进行区分，得到k；
        为了在访问原数组nums[i]-1处的值时进行还原,做出的改变为 使其取反，这样在还原时，取绝对值即可；
        对于原数组中重复出现的数，在改变相应索引对应值时，判断该值是否已经为负数，若是，表明重复，可以跳过。

### 代码

```java
//方法1：
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        for(int n : nums){
            set.add(n);
        }
        for(int i = 1; i <= nums.length; i ++){
            if(!set.contains(i)){
                list.add(i);
            }
        }
        return list;
    }
}
```
```java
//方法2：
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        for(int n : nums){
            set.add(n);
        }
        for(int i = 1; i <= nums.length; i ++){
            if(!set.contains(i)){
                list.add(i);
            }
        }
        return list;
    }
}
```
