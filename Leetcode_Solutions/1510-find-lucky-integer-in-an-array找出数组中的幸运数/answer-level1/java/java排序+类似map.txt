### 解题思路
先排序，排序后统计

### 代码

```java
class Solution {
   public int findLucky(int[] arr) {
        if(arr==null || arr.length==0){
            return -1;
        }
        Arrays.sort(arr);
        int[] dp = new int[501];
        for(int i=0;i<arr.length;i++){
            dp[arr[i]] ++;
        }
        for(int i=500;i>0;i--){
            if(dp[i]!=0 && dp[i] == i){
                return i;
            }
        }
        return -1;
    }
}
```