### 解题思路
**题目要求：** 按照要求重新组织数据。
**思路：**
题目不但要求我们返回数组长度，还要将重复的元素“删除”。也就是说要重新组织原数组中的元素。
最简单的方法就是使用两个指针（变量），一个指向已重新组织的元素，一个指向未处理的元素。
![删除排序数组中的重复项.gif](https://pic.leetcode-cn.com/6b30405f70761d3a8167009131649b914a215e18b2c47299081e3033653411e2-%E5%88%A0%E9%99%A4%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E9%A1%B9.gif)

**快慢双指针代码：**
```java
public int removeDuplicates(int[] nums) {
    int current = 0;    // 慢指针，在当前指针以及左边的元素是已确定的元素
    int index = 1;      // 快指针，用于遍历未确定的元素
    int length = nums.length;
    
    for(; index < length; index++){
        if(nums[current] != nums[index]){
            // 如果两个指针相邻，直接增加索引，可以省去赋值操作
            if(++current == index) continue;
            nums[current] = nums[index];
        }
    }
    return current + 1;
}
```

博客：www.lxiaocode.com