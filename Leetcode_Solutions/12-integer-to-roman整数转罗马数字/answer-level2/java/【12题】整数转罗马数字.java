**方法一：贪心算法**
```
class Solution {
    /**
    * 思路：
    *   由题找出阿拉伯数字和罗马数字之间的对应关系，从大到小逐步替换。
    *   (贪心算法：找出当前每一步的最优解。)
    */
    public String intToRoman(int num) {
        // 把阿拉伯数字与罗马数字可能出现的所有对应关系，从大到小放在两个数组中。
        int[] nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        StringBuilder sb = new StringBuilder();
        int index = 0;
        while (num > 0){
            while (num >= nums[index]){
                sb.append(romans[index]);
                num -= nums[index];
            }
            index++;
        }
        return sb.toString();
    }
}
```
