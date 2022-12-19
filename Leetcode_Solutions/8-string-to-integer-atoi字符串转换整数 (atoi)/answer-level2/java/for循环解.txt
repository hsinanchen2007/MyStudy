### 解题思路
太南了，用for循环加一大堆判断

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        char z = '+';
        char f = '-';
        char min = '0';
        char max = '9';
        char bk = ' ';

        char[] cs = str.toCharArray();
        //存储当前数字是正还是负
        boolean zf = true;
        //判断是否开始分析到数字
        boolean start = false;
        //存储结果
        int res = 0;
        for(int i = 0; i < cs.length; i++){
            char c = cs[i];
            //如果当前还没开始分析数值，且当前字符是空格，则跳过
            if(c == bk && !start){
                continue;
            //发现一个非数字就跳出
            }else if((c != z && c != f && !(c >= min && c <= max))){
                break;
            }
            //判断正负
            if(!start){
                if(c == z){
                    start = true;
                    continue;
                }
                if(c == f){
                    start = true;
                    zf = false;
                    continue;
                }
            }
            //开始分析数值
            start = true;
            //数值
            if(c >= min && c <= max){
                //大于边界判断
                if (res > Integer.MAX_VALUE / 10){
                    if(zf){
                        return Integer.MAX_VALUE;
                    }else{
                        return Integer.MIN_VALUE;
                    }
                }
                //刚好等于边界判断
                else if (res == Integer.MAX_VALUE / 10){
                    if (zf && (c - min) > Integer.MAX_VALUE % 10){
                        return Integer.MAX_VALUE;
                    }else if (!zf && (c - min) > -(Integer.MIN_VALUE % 10)){
                        return Integer.MIN_VALUE;
                    }
                }
                //累加
                res = ((res * 10)  + (c - min));
            }else{
                //找到一个非数字，直接跳出
                break;
            }
        }

        return zf ? res : -res;
    }
}
```