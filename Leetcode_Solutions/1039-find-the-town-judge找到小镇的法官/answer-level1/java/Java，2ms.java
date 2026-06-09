考虑了多人被所有人信任的情况
```
package leetcode;

public class FindtheTownJudge {
    public int findJudge(int N, int[][] trust) {
        int[] count = new int[N + 1];
        for (int i = 0; i < trust.length; i++) {
            if (trust[i][0] == 0)
                break;
            count[trust[i][1]]++;
        }
        /**
         * man:所有人都相信的人
         * manCount:这种人有几个，超过1则返回-1
         */
        int man = -1;
        int manCount = 0;
        //获取所有人都相信的人的标记,若没有则返回-1
        for (int i = 1; i <= N; i++) {
            if (count[i] == N - 1) {
                if (++manCount == 2)
                    return -1;
                man = i;
            }
        }
        //如果这个人相信别人，那么返回-1，否则返回man
        for (int[] t : trust) {
            if (man == t[0]) {
                return -1;
            }
        }
        return man;
    }
}
```


