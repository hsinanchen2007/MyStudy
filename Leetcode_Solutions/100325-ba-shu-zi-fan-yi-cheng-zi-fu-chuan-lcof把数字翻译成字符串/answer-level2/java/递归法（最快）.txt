### 解题思路
击败100%

### 代码

```java
class Solution {
    private int len;
    private String str;

    public int translateNum(int num) {
        str = String.valueOf(num);
        len = str.length();
        return dfs(0);
    }

    private int dfs(int begin) {
        if (begin == len)
            return 1;

        int sum = 0;
        if (begin + 1 < len && str.charAt(begin) != '0' &&
                str.substring(begin, begin + 2).compareTo("25") <= 0){
            sum += dfs(begin + 2) + dfs(begin + 1);
        }else{
            sum = dfs(begin + 1);
        }
        return sum;
    }
}
```