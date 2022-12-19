### 解题思路
1. 能成为公因子的字符串一定来自于较短的哪个字符窜
2. 公因子一定能整除两个字符串，因此公因子是较短哪个字符串的子字符串循环构成
3. 公因子的长度一定能被较短的哪个字符串的长度整除，不能整除的一定不是公因子
4. 结合上述三个特征，有以下解法：
5. 将子字符串作为初始公因子，依次往下降低长度，分两份，分三份，直接分到n份
6. 分到第k份能被整除就是最大公因子

### 代码

```java
class Solution {
    // 思路
    // 选取较小的那个字符串作为公因子
    // 因为要等分，所以只能2等分，3等分，直接到最后把较短的那个字符串分到1，即n等分
    // 递归处理
    public String gcdOfStrings(String str1, String str2) {
        String factor = str1.length() > str2.length()? str2: str1;
        // 从整串开始
        int i = 1;
        int t = factor.length();
        while(factor.length() >= i){
            // 如果对i能够整除
            if(t % i ==0){
                int len = t / i;
                String sub = factor.substring(0, len);
                String str2_rep = str2.replaceAll(sub,"");
                String str1_rep = str1.replaceAll(sub, "");
                if(str1_rep.length() == 0 && str2_rep.length() == 0){
                    return sub;
                }
            }
            i++;
        }
        return "";
    }
}
```