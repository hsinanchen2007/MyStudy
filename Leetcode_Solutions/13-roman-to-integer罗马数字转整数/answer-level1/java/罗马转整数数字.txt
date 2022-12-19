### 解题思路
此处撰写解题思路
1.遍历字符串的每个字符,然后用switch比较
2.如果不包含上述的罗马字符就返回0
3.获取当前的罗马字符代表的数字
4.判断是否大于上个数字,如果大于则减去上个数字*2
5.每次都+=当前罗马字符的结果,最终遍历结束返回
### 代码

```java
class Solution {
    public int romanToInt(String s) {
         int result = 0;
        int last = 0;
        for (int i = 0; i < s.length(); i++) {
            int r;
            switch (s.charAt(i)) {
                case 'I':
                    r = 1;
                    break;
                case 'V':
                    r = 5;
                    break;
                case 'X':
                    r = 10;
                    break;
                case 'L':
                    r = 50;
                    break;
                case 'C':
                    r = 100;
                    break;
                case 'D':
                    r = 500;
                    break;
                case 'M':
                    r = 1000;
                    break;
                default:
                    return 0;
            }
            if (r > last) {
                r = r - last * 2;
                result += r;
            }else {
                result += r;
            }
            last = r;
        }
        if (result > 3999 ){
            return 0;
        }
        return result;

    }
}
```