### 解题思路
一.判断字符串长度是否为0;如果是则直接返回0。
二.遍历去掉首部空字符串，然后判断是否为 + 或 -号，放入sign中(+：sign为1，-：sign为-1)
然后遍历剩下的字符串，如果它大于9或者小于0直接退出循环，最后判断是否越界，用ans=ans*10+a放连续数字。
如果上面条件都不符合，ans还是0；
### 代码

```java
class Solution {
    public int myAtoi(String str) {
        int len = str.length();
        if(len==0) return 0;
        int i = 0,sign = 1,ans = 0;
        while(i < len && str.charAt(i)==' ')
            i++;
        if(i<len&&(str.charAt(i)=='-'||str.charAt(i)=='+')){
            sign = str.charAt(i++)=='-' ? -1 : 1;
        }
        while(i < len){
            int a = str.charAt(i) - '0';
            if(a < 0||a > 9) break;
            if(Integer.MAX_VALUE / 10 < ans || (Integer.MAX_VALUE/10 == ans&& Integer.MAX_VALUE % 10 < a)){
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            ans = ans*10 + a;
            i++;
        }
        return ans * sign;
    }
}
```