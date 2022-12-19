### 解题思路
用动态规划的思想，此时需要保存的值是字符串s中的第i个字符，对应于字符串t中对应的第j个字符，保存为position，之后更新position即可。

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        boolean flag;
        int position = -1;
        for(int i = 0; i < s.length(); i++){
            flag = false;
            for(int j = position+1; j < t.length(); j++){
                if(t.charAt(j) == s.charAt(i)){
                    position = j;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                return false;
            }
        }
        return true;
    }
}
```