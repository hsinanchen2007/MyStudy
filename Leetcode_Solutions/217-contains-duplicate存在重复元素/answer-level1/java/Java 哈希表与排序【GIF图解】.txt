### 解题思路
**题目要求：** 判断数组是否有两个相同的元素。
**思路1：** 
这道题和 `#1 两数之和` 十分的像，都是在数组中寻找符合某条件的两个元素。
所以我们可以照搬 `#1 两数之和` 的思路进行解题。
1. for循环遍历每一个元素，在map中查找与该元素符合条件的元素。
2. 如果map中没有符合条件的元素，则将该元素放入map中。
3. 为下一个元素寻找符合条件的元素。
![存在重复元素1.gif](https://pic.leetcode-cn.com/6072385e525da28dce676d9435bf58b98f9f663b8557a12381906443a223f546-%E5%AD%98%E5%9C%A8%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A01.gif)

**一遍哈希遍历代码：**
```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int length = nums.length;

        for (int i = 0; i < length; i++){
            if (map.containsKey(nums[i])){
                return true;
            }
            map.put(nums[i], i);
        }
        return false;
    }
}
```
**改进：**
思路1显然是可行的，但不是最优的办法。
首先，使用map需要开辟额外的内存空间；其次，对于元素比较少的数组，map在维护其属性的开销比例更大。
所以，我们需要思考不使用map的办法。

**思路2：**
问题又回到了如何寻找两个相同的元素。
既然这两个元素是相同的，那么在有序数组中，相同的元素必然是相邻的。
这样我们只需要在有序的数组中判断相邻的元素是否相同即可。
1. 对数组进行排序。
2. 遍历数组，判断当前元素与下一个元素是否相同。
![存在重复元素2.gif](https://pic.leetcode-cn.com/8c293c0ff0e8b032dd16c6e433c704695db419092033c1795b92f2b7725753ad-%E5%AD%98%E5%9C%A8%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A02.gif)


**排序查找代码：**
```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        int length = nums.length;

        for (int i = 0; i < length - 1; i++){
            if (nums[i] == nums[i + 1]){
                return true;
            }
        }
        return false;
    }
}
```

博客：www.lxiaocode.com