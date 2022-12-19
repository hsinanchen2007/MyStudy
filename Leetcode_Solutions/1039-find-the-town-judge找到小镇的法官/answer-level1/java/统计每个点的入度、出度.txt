### 解题思路
遍历数组trust，统计出每个人的入度和出度。法官满足条件入度为N-1，出度为0。

### 代码

```java
class Solution {
    public int findJudge(int N, int[][] trust) {
      int[] indegree=new int[N+1];
      int[] outdegree=new int[N+1];
      for(int[] path:trust){
          int out=path[0];
          int in=path[1];
          outdegree[out]++;
          indegree[in]++;
      }
      for(int i=1;i<=N;i++){
          if(outdegree[i]==0&&indegree[i]==N-1){
              return i;
          }
      }
      return -1;
    }
}
```