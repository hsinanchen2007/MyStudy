### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int myAtoi(String str) {
 if(str.length()==0){
            return 0;
        }
        //去除字符串的前行空格，找到真正的起始点
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') {
                continue;
            } else {
                count = i;
                break;
            }
        }
        //起始点的三种情况对应不同的解决方法
        boolean flag1 = str.charAt(count) == '+' || str.charAt(count) == '-';
        boolean flag2 = (str.charAt(count) > '0' && str.charAt(count) <= '9');
        boolean flag3 = str.charAt(count) == '0';
        //字符串不有效
        if (!flag1 && !flag2 && !flag3) {
            return 0;
        }
        long res=0L;//定义长整型，用于溢出的判断
        //如果第一个字符为数字，初始化长整型
        if (flag2) {
           res=str.charAt(count)-48;
        }
        for (int i = count + 1; i < str.length(); i++) {
            //如果第一个字符为正负号
            boolean flag=str.charAt(i) >= '0' && str.charAt(i) <= '9';
            if (flag1) {
                if (str.charAt(i) == '0' && res == 0) {//在出现非0数字前只要是0就一直向后找
                    continue;
                } else if (flag) {//如果是数字，就加入long中进行运算
                   res=res*10+str.charAt(i)-48;//每加入一次判断是否溢出
                    if(str.charAt(count)=='+'){
                        if(res>Integer.MAX_VALUE){
                            return Integer.MAX_VALUE;
                        }
                    }else{
                        res=-res;
                      if(res<Integer.MIN_VALUE){
                          return Integer.MIN_VALUE;
                      }
                      res=-res;
                    }
                } else {//不是数字就退出
                    break;
                }
            } else if (flag2) {//第一个字符为数字而且不为0
                if (flag) {
                    res=res*10+str.charAt(i)-48;
                    if(res>Integer.MAX_VALUE){
                        return Integer.MAX_VALUE;
                    }
                } else {
                    break;
                }
            } else if (flag3) {//第一个字符为零
                if (str.charAt(i) == '0' &&res == 0) {
                    continue;
                } else if (flag) {
                    res=res*10+str.charAt(i)-48;
                    if(res>Integer.MAX_VALUE){
                        return Integer.MAX_VALUE;
                    }
                } else {
                    break;
                }
            }
        }
        if(str.charAt(count) == '-'){
            res=-res;
        }
        return (int)res;
    }
}
```