### 解题思路
注意0x这种情况

### 代码

```java
class Solution {
    int ans = 0;
    public int translateNum(int num) {
    String str = String.valueOf(num);
    dfs(str,0);
    return ans;
    }
    public void dfs(String str, int n)
    {
        if(n == str.length())
        {
            ans++;
            return;
        }
        if(Integer.valueOf(str.substring(n,n+1)) <= 25)
        {
            dfs(str,n+1);
        }
        if(n != str.length() -1 && Integer.valueOf(str.substring(n,n+2)) <= 25 && !str.substring(n,n+1).equals("0"))
        {
            dfs(str,n+2);
        }
    }
}
```