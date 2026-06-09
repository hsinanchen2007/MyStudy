
- 法官不相信任何人，说明法官不存在出度
- 所有人都信任法官，说明法官的入度为N-1
- 那么法官的出度加入度为N-1

```
public int findJudge(int N, int[][] trust) {
        int[] cnt = new int[N+1];//统计出入度
        for (int[] index : trust) {
	        cnt[index[0]]--;//出度--
	        cnt[index[1]]++;//入度++
	}
        for ( int i = 1; i <= N; i++ ) {
        	if ( cnt[i] == N-1 ) return i;
        }
        return -1;
    }
```
