我不是自己想出来的，也是看别人的题解才懂得。
第一步：先判断二者有没有可以将两个字符串都除尽的因子
        这里我们可以根据 str1 + str2 == str2 + str1 来判断
        注意：java中要用equals()方法即 (str1 + str2).equals((str2 + str1))来判断，因为Java中用 == 比较字符串是否相等
              比较的是地址，我们需要比的是内容是否相同。

第二步：实际上就是找两个字符串长度的最大公因数，用gcd()方法就好了
```
    class Solution {
        public String gcdOfStrings(String str1, String str2) {
            String s1 = str1 + str2;
            String s2 = str2 + str1;
            if (!s1.equals(s2))
                return "";
            int index = 0;
            index = gcd(str1.length(), str2.length());
            return str1.substring(0, index);
        }

        private int gcd(int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        }
    }
```

    

            