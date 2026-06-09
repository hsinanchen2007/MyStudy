```
class Solution {
    public int gcd(int a, int b) {
        while(b != 0) {
            int tmp = a;//需要同时保存处理
            a = b;
            b = tmp % b;
        }
        return a;
    }
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1 + str2).equals(str2 + str1)) return "";//若有最大公约，前后链接应该一致
        return str2.substring(0, gcd(str1.length(), str2.length()));//字符串长度用.length()计算，数组是用.length
    }//子串使用substring(m, n)截取
}
```

```
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""
        def gcb(a, b):
            while b != 0:
                a, b = b, a % b
            return a
        lens = gcb(len(str1), len(str2))
        return str2[:lens]
```
