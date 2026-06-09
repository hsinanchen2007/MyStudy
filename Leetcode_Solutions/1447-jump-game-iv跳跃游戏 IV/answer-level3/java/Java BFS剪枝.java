### 解题思路
![1.png](https://pic.leetcode-cn.com/67627855177606dff772b46350b874b4f3ceb9539036b5ec29a5dd227eba5e02-1.png)

Java BFS剪枝

### 代码

```java
import java.util.*;
class Solution {
    public int minJumps(int[] arr) {
        int n=arr.length,res=0,end=0;
        Map<Integer,List<Integer>> map=new HashMap<>();
        int[] dp=new int[n];
        Arrays.fill(dp,999999);
        dp[0]=0;
        for(int i=0;i<n;i++){
            List<Integer> temp;
            if(map.containsKey(arr[i]))
                temp=map.get(arr[i]);
            else
                temp=new ArrayList<>();
            temp.add(i);
            map.put(arr[i],temp);
        }
        Queue<Integer> q=new LinkedList<>();
        q.add(0);
        while(!q.isEmpty()){
            int t=q.poll();
            if(t>0&&dp[t-1]==999999){
                dp[t-1]=Math.min(dp[t-1],dp[t]+1);
                q.add(t-1);
            }
            if(t<n-1&&dp[t+1]==999999){
                dp[t+1]=Math.min(dp[t+1],dp[t]+1);
                q.add(t+1);
            }
            if(map.containsKey(arr[t])){
                for(int i:map.get(arr[t])){
                    if(i!=t&&dp[i]==999999) {
                        dp[i]=Math.min(dp[i],dp[t]+1);
                        q.add(i);
                        if(i==n-1)
                            return dp[i];
                    }
                }
                map.remove(arr[t]);
            }
        }
        return dp[n-1];
    }
}
```