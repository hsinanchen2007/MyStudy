首先此题的思路与[7. 整数反转](https://leetcode-cn.com/problems/reverse-integer/)相似，都是将数字或者字符转化成整数，其中涉及到了整数越界问题。
需要注意的几点：
1. 字符开始结尾可能出现空格，应首先剔除掉再进行接下来判断；
2. 当去除空格后，字符串头部会出现以下几种类型:开始为“-”、开始为“+”，开始为数字、开始为其他字符。当开头第一个字符为“+”或者“-”号时，我们将遍历开始位置设置为第二个字符。同时将“-”的符号记录下来，令flag = -1。
3. 从设置的开始位置遍历字符，并进行运算。此时需符合的遍历条件是，遍历的字符为数字字符。计算的时候注意将符号同时计算在内。
4. 计算越界问题。pop为新增的计算数，ans为结果。
```
//什么情况会向上溢出？ ans * 10 + pop > MAX  因为计算后越界影响计算结果，所以提前进行越界计算，相当于移动等式两边部分
//ans = MAX / 10 && pop > MAX % 10 或 ans > MAX / 10
//什么情况会向下溢出？ ans * 10 + pop < MIN
//ans = MIN / 10 && pop < MIN % 10 或 ans < MIN / 10
if(ans > MAX / 10 || (ans == MAX / 10 && pop > MAX % 10)) return 0;
if(ans < MIN / 10 || (ans == MIN / 10 && pop < MIN % 10)) return 0;
```

从高位往低位组成整数一般形式：
```
int ans = 0;
int[] nums = {3, 1, 4, 1, 5, 9, 2, 6};
for(int i = 0; i < nums.length; i++){
    ans = ans * 10 + nums[i];
}
```

```
class Solution {
    public int myAtoi(String str) {
        if(str == null) return 0;
        String str1 = str.trim();
        if(str1.length() == 0) return 0;//去掉字符串中开始和结尾的空格
        int flag = 1;//默认正数计算
        int i = 0;//默认无符号从0开始
        if(str1.charAt(0) == '-'){
            flag = -1;
            i = 1;
        }else if(str1.charAt(0) == '+'){
            i = 1;
        }
        int ans = 0;
        while( i < str1.length() && str1.charAt(i) >= '0' && str1.charAt(i) <= '9'){
            int n = (str1.charAt(i) - '0') * flag;//转化为数字 包括符号
            if(ans > Integer.MAX_VALUE / 10 || (ans == Integer.MAX_VALUE / 10 && n > 7)){
                return Integer.MAX_VALUE;
            }
            if(ans < Integer.MIN_VALUE / 10 || (ans == Integer.MIN_VALUE / 10 && n < -8)){
                return Integer.MIN_VALUE;
            }
            ans = ans * 10 + n;
            i++;
        }
        return ans;

    }
}
```