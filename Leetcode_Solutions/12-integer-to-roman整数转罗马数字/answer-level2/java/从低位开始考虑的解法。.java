以三个为一组，观察一下罗马数字符号，发现按照10的倍数增加，正好和10位进制匹配，所以高位的可以通过不断模10最终转换为低位1-10之间的简单数字转罗马数字问题。不过是表示的罗马数字符号不同罢了，用一个计数器来记录这个不同，从字符串中取出当前匹配的罗马数字符号即可。

```
class Solution {
    public String intToRoman(int num) {
        String res = "";
        String con = "IVXLCDM";
        int len = con.length();
        int cou = 0;
        while(num>0){
            int n = num % 10;
            String a = (cou < len)?String.valueOf(con.charAt(cou)):"";
            String b = (cou + 1 < len)?String.valueOf(con.charAt(cou + 1)):"";
            String c = (cou + 2 < len)?String.valueOf(con.charAt(cou + 2)):"";
            if(n == 4)
                res = a + b + res;
            else if(n == 9)
                res = a + c + res;
            else{
                if(n % 5 > 0){
                    for(int i = 0;i < n % 5;i++)
                        res = a + res;
                }
                if(n / 5 > 0)
                    res = b + res;
            }
            cou += 2;
            num = num / 10;
        }
        return res;
        
    }
}
```

扩展起来很方便，直接在con后加就行。

执行用时29ms,内存消耗43M。将len直接改为7的执行用时是15ms。