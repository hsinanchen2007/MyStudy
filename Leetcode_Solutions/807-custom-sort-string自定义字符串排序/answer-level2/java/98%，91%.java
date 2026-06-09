### 解题思路
![微信图片_20200205225317.png](https://pic.leetcode-cn.com/41607f125931963da890525bb8b6417691e86da72548c095c1269352e767a8dd-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200205225317.png)

三个循环体：
1.计算目标数组每个字母的个数
2.根据reference开始循环输出
3.最后添加reference中没有出现的字母

### 代码

```java
class Solution {
    public String customSortString(String S, String T) {
        StringBuilder sb=new StringBuilder();
        int []cnt=new int[26];
        for (char i:T.toCharArray())
            cnt[i-'a']++;

        for (int i=0;i<S.length();i++){
            for (int j=0;j<cnt[S.charAt(i)-'a'];j++){
                sb.append(S.charAt(i));
            }
            cnt[S.charAt(i)-'a']=0;
        }
        for (int i=0;i<26;i++){
            if (cnt[i]!=0){
                for (int j=0;j<cnt[i];j++){
                    sb.append((char)(i+'a'));
                }
            }
        }
        return sb.toString();
    }
}
```