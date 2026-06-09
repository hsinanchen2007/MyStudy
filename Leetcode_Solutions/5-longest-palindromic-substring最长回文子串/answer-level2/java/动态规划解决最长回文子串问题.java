### 解题思路
有点类似于斐波那契函数数列解决方案。判定从i到j的字符串是否是回文：
1、如果长度小于等于2，直接判断（是否相等）
2、否则，判断当前i和j的字符是否相等，以及i+1到j-1之间的字符串是否相等
3、将判断出的回文子串和原来比较，取最长回文子串

注意：双重遍历是要注意遍历方向，步骤2中要取[i+1到j-1之间的字符串是否相等]，如果遍历顺序不对，会出错（我就是这个地方出错了）

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        //存储s的char集合
        char[] chars=s.toCharArray();
        String ans = "";
        //存储从i到j的子串是否是回文字符串
        boolean[][] LPS=new boolean[s.length()][s.length()];
        //对字符串双重遍历，判断从i到j的子串是否是回文字符串
        //要保证最早被调用的LPS先得到结果
        for (int i=0;i<LPS.length;i++){
            for (int j=0;j<=i;j++){
                //子串长度小于等于2，单独处理
                if (i-j<2){
                    LPS[j][i]=(chars[i]==chars[j]);
                }else {
                    //当前子串的子串一定是回文字符串
                    LPS[j][i]=LPS[j+1][i-1]&&(chars[i]==chars[j]);              
                }

                //刷新最长回文字符串,当前子串是回文字符串，并且长度比之前的最长回文子串要长
                if (ans.length()<(i-j+1)&&LPS[j][i]){
                    ans=s.substring(j,i+1);
                }
            }
        }


        return ans;
    }
}
```