### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败100.00%的用户
内存消耗 :36.6 MB, 在所有 Java 提交中击败了5.02%的用户

### 代码

```java
class Solution {
    public String convertToTitle(int n) {
        if(n == 0)
            return "";
        String[] s = {"A","B","C","D","E","F","G","H","I","J","K","L",
                "M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        if(n < 26)
            return s[n - 1];
        StringBuilder sb = new StringBuilder("");
        while (n > 0){
            int tmp = n % 26;
            if(tmp == 0){
                tmp = 26 ;
                n = n -1;
            }
            sb.insert(0, s[tmp - 1]);
            n = n / 26;
        }
        return sb.toString();
    }
}
```