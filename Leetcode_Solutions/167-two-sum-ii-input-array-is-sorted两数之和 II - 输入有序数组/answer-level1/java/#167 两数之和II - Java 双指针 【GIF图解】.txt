### 解题思路
**思路：**
与 #1 两数之和 不同，#167 两数之和II 输入的数组是已排序的。即索引递增，元素也递增；索引递减，元素也递减。
分别使用 index1、index2 指向数组的开头和结尾元素，计算两数之和。
1. 若小于目标值，index1 递增。
2. 若大于目标值，index2 递减。
3. 若等于目标值，返回 index1+1 、index2+1。
![167两数之和II.gif](https://pic.leetcode-cn.com/fa5a917fbe972c390533905c46a07fa051d5b258a5f4845afd7faa895874c2b3-167%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8CII.gif)

**双指针代码：**
```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        // 左右指针
        int index1 = 0;
        int index2 = numbers.length - 1;
        int sum = 0;
        
        while(index1 < index2){
            sum = numbers[index1]+numbers[index2];
            if (sum == target){
                return new int[]{index1 + 1 , index2 + 1};
            }
            
            // 小了，index1向右移；大了，index2向左移
            if (sum < target)   
                index1++;
            else 
                index2--;
        }
        
        return null;
    }
}
```

博客：www.lxiaocode.com