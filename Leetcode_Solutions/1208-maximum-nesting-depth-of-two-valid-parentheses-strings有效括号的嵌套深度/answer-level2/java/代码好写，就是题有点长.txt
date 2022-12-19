### 解题思路
a 表示A串当前“(”的个数，b 表示B串当前“(”的个数。遇到“)”时，先与A串匹配，匹配到“)”后，个数减1。

我看了别人的按奇偶分配，意思差不多，区别在于，如果遇到很多个连续的左括号，接着又是很多连续的右括号。按奇偶分会是01010101010101而我的会是010101000111。最终形成的串其实是一样的。

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        if (seq.length() == 0) return new int[0];
        int length = seq.length();
        int[] ans = new int[length];
        int a = 0;
        int b = 0;
        for (int i = 0; i < length; i++){
            if ('(' == seq.charAt(i)){
                if (a > b){
                    ans[i] = 1;
                    b += 1;
                }else{
                    a += 1;
                }
            }else{
                if (a > 0){
                    a -= 1;
                }else{
                    ans[i] = 1;
                    b -= 1;
                }
            }
        }
        return ans;
    }
}
```