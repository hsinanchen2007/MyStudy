贪心的思想
先按会议结束的位置排序
然后使用一个vis数组记录该天是否已经使用
遍历会议，从start 到end 使用靠前的day用来参加会议（贪心思想）

```
class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[1]!=o2[1]) return o1[1]-o2[1];
                else return o1[0]-o2[0];
            }
        });
        boolean[] vis=new boolean[100005];
        int res=0;
        for(int[] it:events){
            for(int i=it[0];i<=it[1];i++){
                if(vis[i]==false){
                    vis[i]=true;
                    res++;
                    break;
                }
            }
        }
        return res;
    }
}
```
