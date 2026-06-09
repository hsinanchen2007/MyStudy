### 解题思路
本题和13题的题目完全相反

**整数转罗马数字**首先是要建立**两个对应的数组**，依次从大的整数开始判断是否符合，则将对应的罗马数字加入到ans中

每加进去一个罗马数字，都要记得用num减去nums数组里面的整数，依次从大的值向小的值进行判断，直到遍历完整数数组nums

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        int[] nums = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int index = 0;
        StringBuilder ans = new StringBuilder();
        while(index < 13){//遍历整个nums数组
            while(num >= nums[index]){//从最大值开始比较
                ans.append(romans[index]);//满足nums里面的数值，就将romans里面的字母加进去
                num -= nums[index];               
            }
            index++;
        }
        return ans.toString();
    }
}
```