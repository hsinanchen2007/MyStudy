第一次遍历将每个元素交换到其元素值对应的下标出，第二次遍历检查每个元素的值和其下标是否相等，如不相等则这个下标就是缺失的第一个正数。

1. 第一次遍历：
   - 将所有符合`nums[i]大于0且小于length`的元素交换到其值对应的下标位置，例如2应当交换到nums[2]的位置、6应当交换到nums[6]的位置。
   - 如果`nums[i]==nums[nums[i]]`则不需要移动，例如nums[0]\==3但是nums[3]==3就不需要移动了。
   - 交换之后再检查nums[i]是否依然需要交换，如果需要交换继续交换，直至nums[i]无需交换再继续向后遍历。

2. 第二次遍历：
   - 从1开始，如果`nums[i]!=i`则i就是缺失的第一个正数。
3. 两次遍历结束后：
   - 如果没有找到缺失的第一个正数，就检查`nums[0]==length`如果相等则返回length+1，否则返回length

```java
public int firstMissingPositive(int[] nums) {
    if (nums==null||nums.length==0)return 1;
    for (int i = 0; i < nums.length; i++) {
        while (nums[i]>0&&nums[i]<nums.length&&nums[i]!=nums[nums[i]]){
            int temp=nums[nums[i]];
            nums[nums[i]]=nums[i];
            nums[i]=temp;
        }
    }
    for (int i = 1; i < nums.length; i++) {
        if (nums[i]!=i)return i;
    }
    if (nums[0]==nums.length)return nums.length+1;
    return nums.length;
}
```

时间复杂度：O(n)

---
本人菜鸟，有错误请告知，感激不尽！

更多题解和学习记录博客:[博客](https://blog.csdn.net/qq_42758551)**、**[github](https://jerrymouse1998.github.io/)