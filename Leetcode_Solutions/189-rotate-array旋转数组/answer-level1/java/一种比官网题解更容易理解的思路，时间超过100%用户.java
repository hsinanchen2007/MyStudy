## 题解思路
有两个地方会比官方题解更加容易理解：1. 临时数据存储；2.移动替换
由于是移动k个元素，那么我们可以直接把最后（k%数组长度）存储到tmpNums的数组（长度为k的数组）中，然后把前面numsLength-k个数组进行向后移动，然后把tmpNums数组中的数字顺序赋值给原数组的前k个就完成了移动。
## 执行结果
![image.png](https://pic.leetcode-cn.com/ba333f7a5ce4ba3ef22a1786954fd53bc352ad224ac94bc0a131fe91aacc595e-image.png)
## 代码
```
/**
 * @author michael
 *使用k个数组进行保存临时变量
 */
class Solution {
    public void rotate(int[] nums, int k) {
        int numsLength = nums.length;
        k = k % numsLength;
        int tmpNums[] = new int[k];
        if (numsLength == 1) {
            return;
        }
        int countIndex = 0;
        for (int index = numsLength-k; index < numsLength; index++) {
            tmpNums[countIndex] = nums[index];
            countIndex++;
        }
        for (int index = numsLength-k-1; index >= 0; index--) {
            nums[index+k] = nums[index];
        }
        for (int index = 0; index < k; index++) {
            nums[index] = tmpNums[index];
        }
    }
}
```
