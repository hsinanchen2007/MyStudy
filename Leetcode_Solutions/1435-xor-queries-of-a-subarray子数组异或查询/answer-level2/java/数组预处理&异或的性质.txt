### 解题思路
简单的预处理，使用一个异或的性质

### 代码

```java
class Solution {
    /**
    * 注意：a ^ b = c , c ^ b = a ,常用于密码加密
    */
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] oxr = new int[arr.length];
        int[] ans = new int[queries.length];
        oxr[0] = arr[0];
        for(int i=1;i<arr.length;i++)
            oxr[i] = oxr[i-1] ^ arr[i];
        for(int i=0;i<queries.length;i++){
            if(queries[i][0]==queries[i][1])
                ans[i] = arr[queries[i][0]];
            else if(queries[i][0]==0)
                ans[i] = oxr[queries[i][1]];
            else 
                ans[i] = oxr[queries[i][1]] ^ oxr[queries[i][0]-1];
        }
        return ans;
    }
}
```