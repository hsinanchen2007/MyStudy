### 题目
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

- 返回的下标值（index1 和 index2）不是从零开始的。
- 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

示例:

	输入: numbers = [2, 7, 11, 15], target = 9
	输出: [1,2]
	解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted

### 解题思路

#### 前置条件
[Leetcode 题解 - 目录.md](https://github.com/CyC2018/CS-Notes/blob/master/notes/Leetcode%20%E9%A2%98%E8%A7%A3%20-%20%E7%9B%AE%E5%BD%95.md)

由热门题解提供的图片可知
![image.png](https://pic.leetcode-cn.com/396dc5508fb8ff2b346cdc7d31f6ed4d189878685d7364fbd2a4036131c8dfeb-file_1583249652882)

	由约束条件(其中 index1 必须小于 index2)的限制，搜索空间是白色的倒三角部分。
	可以看到，搜索空间的大小是 O(n^2) 数量级的。
	如果用暴力解法求解，一次只检查一个单元格，
	那么时间复杂度一定是 O(n^2)。要想得到 O(n) 的解法，我们就需要能够一次排除多个单元格。


#### 笔记
	通过双指针,至于为什么想到双指针,因为从一个方向开始,时间复杂度会很高.   

	咱们只考虑第一层循环,如果sum大于target,说明值大了,如果i增加只会更大,所以只能j--了.这就排除了j不动,i增加的那一排空格了. 
	
	如果sum小于target,说明值小了了,但是j已经是最大了,所以只能i++,所以就排除了,i不变,j--的哪一排空格.   
	
	第二层循环同理.
	
	注:循环条件的选择,while (i < j) 没看答案没有想到,希望明天得双指针问题,认真读题,今天是没怎么读题就看答案了.

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        if(numbers == null){
            return null;
        }
        int i = 0;
        int j = numbers.length - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                return new int[]{i+1, j+1};
            }
        }
        return null;
    }
}
```