**方法一：贪心截取**
```
class Solution {
    /**
    * 思路：
    *   输入确保在 1~3999 范围内。
    *   由题找出阿拉伯数字和罗马数字之间的对应关系，从大到小逐步替换。
    *   (贪心算法：找出当前每一步的最优解。)
    */
    public int romanToInt(String s) {
        // 把阿拉伯数字与罗马数字可能出现的所有对应关系，从大到小放在两个数组中。
        int[] nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int ans = 0;
        int index = 0;
        while (s.length() > 0){
            while (s.startsWith(romans[index])){
                ans += nums[index];
                s = s.substring(romans[index].length());
            }
            index++;
        }
        return ans;
    }
}
```

**方法二：单字符遍历**
```
class Solution {
    /**
    * 思路：
    * 输入确保在 1~3999 范围内。
    * (1) 从头遍历罗马数字的每一个字符，根据字符对应的阿拉伯数值比较。
    *   如果小于后一个字符对应的阿拉伯数值，则结果减去当前字符对应的阿拉伯数值，
    *   否则结果加上当前字符对应的阿拉伯数值。
    * (2) 返回最终结果就是转换后的阿拉伯数字。
    */
    public int romanToInt(String s) {
        int sum = 0;
        int preNum = getValue(s.charAt(0));
        for(int i = 1;i < s.length(); i++) {
            int num = getValue(s.charAt(i));
            if(preNum < num) {
                sum -= preNum;
            } else {
                sum += preNum;
            }
            preNum = num;
        }
        // 加上最后一位字符转换后的数值。
        sum += preNum;
        return sum;
    }
    
    private int getValue(char ch) {
        switch(ch) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
}
```
