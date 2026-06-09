### 解题思路
方法：
    分为两种情况：
            1.当a和b都还有值时，通过while和并，通过取余和除控制增量和当前位；
            2.a或者b种某个值消耗完，通过while调用完所有。
![image.png](https://pic.leetcode-cn.com/bc264a294e39c52553b4675a4e0c8094e3e9caf14bc73b381fbb20ae79131b29-image.png)

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
                char[] chara = a.toCharArray();
        char[] charb = b.toCharArray();

        int alen = chara.length - 1;
        int blen = charb.length - 1;

        int val = 0;
        StringBuilder sb = new StringBuilder();
        while (alen >= 0 && blen >= 0) {
           sb.append((val + (charb[blen] - '0' + chara[alen] - '0')) % 2);
            val = (val + (charb[blen] - '0' + chara[alen] - '0')) / 2;
            alen--;
            blen--;
        }

        while (alen >= 0) {
            sb.append((val + (chara[alen] - '0')) % 2);
            val = (val + (chara[alen] - '0')) / 2;
            alen--;
        }

        while (blen >= 0) {
            sb.append((val + (charb[blen] - '0')) % 2);
            val = ((charb[blen] - '0') + val) / 2;
            blen--;
        }
        if ( val == 1 ) {
            sb.append(1);
        }
        return sb.reverse().toString();
    }
}
```