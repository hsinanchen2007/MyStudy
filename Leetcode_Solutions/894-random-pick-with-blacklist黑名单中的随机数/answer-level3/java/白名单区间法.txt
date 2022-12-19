执行用时 :
74 ms
, 在所有 java 提交中击败了
98.25%
的用户
内存消耗 :
68.6 MB
, 在所有 java 提交中击败了
90.00%
的用户

维护一个白名单区间,从区间里取值
```
class Solution {
  private Random rand =new Random();
    private int N;
    private int[] blacklist;
    ArrayList<ArrayList<Integer>> lists;
    public Solution(int N, int[] blacklist) {
        lists = new ArrayList<>(N & 0xffff);
        if(blacklist.length==0){
            ArrayList<Integer> list=new ArrayList<>(2);
            list.add(0);
            list.add(N-1);
            lists.add(list);
        }else {
            this.N = N;
            this.blacklist = blacklist;
            Arrays.sort(blacklist);


            if (blacklist[0] > 0) {
                ArrayList<Integer> list = new ArrayList<>(2);
                list.add(0);
                list.add(blacklist[0] - 1);
                lists.add(list);
            }
            for (int i = 0; i < blacklist.length - 1; ++i) {
                if (blacklist[i] + 1 != blacklist[i + 1]) {
                    ArrayList<Integer> list = new ArrayList<>(2);
                    list.add(blacklist[i] + 1);
                    list.add(blacklist[i + 1] - 1);
                    lists.add(list);
                }
            }
            if (blacklist[blacklist.length - 1] != N - 1) {
                ArrayList<Integer> list = new ArrayList<>(2);
                list.add(blacklist[blacklist.length - 1] + 1);
                list.add(N - 1);
                lists.add(list);
            }
        }
    }
    public int pick() {
        int m=rand.nextInt(lists.size());
        List<Integer> list=lists.get(m);
        int t=list.get(1)-list.get(0);
        if(t==0)
            return list.get(1);
        int n=rand.nextInt(t+1);
        return list.get(0)+n;
    }
}

```
