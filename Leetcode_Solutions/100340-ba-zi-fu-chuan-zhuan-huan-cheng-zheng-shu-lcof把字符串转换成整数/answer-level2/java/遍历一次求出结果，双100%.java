```
public int strToInt(String str) {
        char[] chars = str.toCharArray();
        int len = chars.length;
        //这里f表示正负
        long res = 0, pow = 10, f = 1;
        //start表示是否遇到+-和数字
        boolean start = false;
        for (int i = 0; i < len; i++) {
            //遇到空格直接跳出本次循环
            if (chars[i] == ' ' && !start){
                continue;
            }
            //如果还没遇到+-和数字并且第一次遇到-
            else if (chars[i] == '-' && !start) {
                start = true;
                f = -1;
                continue;
            }
            //如果还没遇到+-和数字并且第一次遇到+
            else if (chars[i] == '+' && !start){
                start = true;
                continue;
            }
            if (chars[i] >= '0' && chars[i] <= '9') {
                start = true;
                res = res * pow + f * (chars[i] - '0');
                if (res >= Integer.MAX_VALUE) return Integer.MAX_VALUE;
                else if (res <= Integer.MIN_VALUE) return Integer.MIN_VALUE;
            }
            //遇到的是无法转换的字符
            else {
                break;
            }
        }
        //由于上面已经做了判断，程序进行到这里说明res一定是int支持以内的值，放心强转
        return (int)res;
    }
```
