主体步骤是循环累加字符串字符对应的数值，针对小大的特殊罗马字符对，我是这么处理的：循环的同时检查当前字符的数值是否大于前一个字符的数值，如果是则双倍减去前一个字符的数值。


```
class Solution {
    public int romanToInt(String s) {
        char[] sList = s.toCharArray();
        int out = getInt(sList[0]);
        int i = 1;
        int len = s.length();

        while(i<len) {
            if(getInt(sList[i])>getInt(sList[i-1])) {
                out -=2*getInt(sList[i-1]);
            }
            out += getInt(sList[i]);
            i++;
        }
        return out;
    }

    int getInt(char romint) {
        int out = 0;
        switch(romint) {
            case 'I' : out = 1; break;
            case 'V' : out = 5; break;
            case 'X' : out = 10; break;
            case 'L' : out = 50; break;
            case 'C' : out = 100; break;
            case 'D' : out = 500; break;
            case 'M' : out = 1000; break;
            default :System.out.println("error romint");
        }
        return out;
    }
}
```
