### 解题思路
由于该题包含两个出现一次的数，解题的关键在于，如何将这两个数区分开，放到两个不同数组中，然后可借助题目 [只出现一次的数字](https://leetcode-cn.com/problems/single-number/) 进行求解
1、将这两个数区分开:将数组中元素异或后所得结果，为那两个数的不同特征，左移记录某个位置特征为mask
2、遍历数组，用mask与数组元素进行&运算，不为零，说明该位置与其相同；为零，说明该位置与其不同
   分别进行异或运算，求出结果。

异或运算：得出不相同的特征
与运算：判断某位置是否相同
### 代码

```java
class Solution {
    public int[] singleNumber(int[] nums) {
        int differ = nums[0];
        for (int i = 1;i<nums.length;i++){
            differ^=nums[i];
        }

        int mask = 1;
        while ((mask&differ)==0){
            mask <<= 1;
        }

        int num1 = 0;
        int num2 = 0;

        for (int i : nums){
            if ((i&mask)!=0){
                num1^=i;
            }else {
                num2^=i;
            }
        }

        return new int[]{num1, num2};
    }
}
```