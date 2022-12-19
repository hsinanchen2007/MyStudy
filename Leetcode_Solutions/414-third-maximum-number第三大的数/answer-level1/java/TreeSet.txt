### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int thirdMax(int[] nums) {
//先判断数组中的元素是不是空，数据是不是合法的
        if (nums == null || nums.length == 0) throw new RuntimeException("error");
//定义一个treeSet自动排序，并且去重
        TreeSet<Integer> set = new TreeSet<>();
//把数组中的元素都放到set里
        for (Integer elem : nums) {
            set.add(elem);
//如果set的元素个数大于了3，那么我们就把第一个位置的值移除去。因为是排好序的，第一个数为最小的一个。我们保证set里只存放3个元素，第一个元素就是第三个大的数
            if (set.size() > 3) set.remove(set.first());
        }
        //判断set元素个数是大于还是小3，小于的把set最后一个元素返回来也就是最大的。如果不是小于3的。那就返回第一个。也就是第三大的元素
        return set.size() < 3 ? set.last() : set.first();   // set.last() 里面最大的元素
    }


}
```