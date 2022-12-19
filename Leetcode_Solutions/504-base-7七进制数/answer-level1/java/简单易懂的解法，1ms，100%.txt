![image.png](https://pic.leetcode-cn.com/d836050aa16f7b0f2455cd06bfd0abc86ea4305710818d5df55548ec1ce1c3b5-image.png)

其实就是除7倒叙取余，字符串相加，注意是左加。
然后正负区别，定义一个标志变量。
```
class Solution {
    public String convertToBase7(int num) {
        //排除0的特殊情况
        if (num == 0)return "0";
        //定义一个boolean类型变量标志来区别正负
        boolean flag = false;
        if (num < 0){
            num *= -1;
            flag = true;
        }
        //定义字符串变量用来存储每次对7的余
        String ans = "";
        int digit = 0;
        while (num > 0){
            digit = num % 7;
            ans = digit + ans;
            num = num / 7;
        }
        //判断正负，是负数就加上 "-"号
        if (flag){
            ans = "-" + ans;
        }
        
        return ans;
    }
}
```
