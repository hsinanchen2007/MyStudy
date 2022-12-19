如果存在最大子串则str1+str2 = str2+str1
然后再求出两者长度的最大公约数
```
    public String gcdOfStrings(String str1, String str2) {
        if (!(str1+str2).equals(str2+str1)) return "";
        int sub = gcd(str1.length(),str2.length());
        return str1.substring(0,sub);
    }

    private int gcd(int l1, int l2) {
        if (l1 == 0) return l1;
        int r;
        while (l2 > 0){
            r = l1 % l2;
            l1 = l2;
            l2 = r;
        }
        return l1;
    }

```
