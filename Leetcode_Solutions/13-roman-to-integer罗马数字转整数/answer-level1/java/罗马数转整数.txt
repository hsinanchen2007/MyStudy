### 解题思路
我这里使用的是从尾部开始往前遍历，一般情况下当前字符对应的数值大于后面字符对应的数值就需要做减法，这时两位才能代表一个数值，因此这里需要进行两步移动，如果字符的对应数值小于后面对应的数值只需要简单进行加法，此时步长为1；

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        HashMap<Character,Integer> aa = new HashMap<Character,Integer>();
        aa.put('I',1);
        aa.put('V',5);
        aa.put('X',10);
        aa.put('L',50);
        aa.put('C',100);
        aa.put('D',500);
        aa.put('M',1000);
        int i = s.length() - 1;
        char a;
        char b;
        int res = 0;
        while(i>=0) {
            a = s.charAt(i);
            if (i > 0) {
                b = s.charAt(i - 1);
                if (aa.get(a) > aa.get(b)) {
                    if (b == 'I' && (a == 'V' || a == 'X')) {
                        res += aa.get(a) - aa.get(b);
                    } else if (b == 'X' && (a == 'L' || a == 'C')) {
                        res += aa.get(a) - aa.get(b);
                    } else if (b == 'C' && (a == 'D' || a == 'M')) {
                        res += aa.get(a) - aa.get(b);
                    } else {
                        return 0;
                    }
                    i -= 2;
                } else {
                    res += aa.get(a);
                    i--;
                }
            }else{
                res +=aa.get(a);
                i--;
            }
        }
        return res;
    }
}
```