### 解题思路
    本题巧妙的利用了图中出度和入度的概念，法官不信任任何人，说明他的出度为0，而所有人都信任法官，说明他的入度为N-1。那么设计一个数组统计所有人的出度和入度，最终入度为N-1且没有出度的人就是法官。
### 代码

```java
class Solution {
    public int findJudge(int N, int[][] trust) {
        int [] cnt=new int[N+1];
        for(int [] index:trust)
        {
           cnt[index[0]]--;  //出度
           cnt[index[1]]++;  //入度
        }
        //查找出度为0，且入度为N-1的元素
        for(int i=1;i<=N;i++)
        {
            if(cnt[i]==N-1)
                return i;
        }
        return -1;
    }
}
```