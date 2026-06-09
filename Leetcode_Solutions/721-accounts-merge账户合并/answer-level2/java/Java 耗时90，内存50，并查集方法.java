显然，这是图的bfs或者dfs，或者并查集。
二话不说 先构造一个带有路径压缩的并查集。
```
    class bingcha {
        int[] bc;
        public bingcha(int n) {
            bc=new int[n];
            init();
        }
        public void init() {
            for(int i=0;i<bc.length;i++) {
                bc[i]=-1;
            }
        }
        public int find(int x) {
            if(bc[x]<0) {
                return x;
            }else{
                bc[x] = find(bc[x]);
            }
            return bc[x];
        } 
        public void combine(int x,int y) {
            int xx = find(x);
            int yy = find(y);
            if(xx!=yy) {
                bc[yy] =xx;
            }
        }
    }
```
看题目，我们要构造一个Map，保存邮箱到人（不能是人名，要是accounts的下标，因为人名会重复）
```
Map<String,Integer> map = new HashMap<>();
```
然后呢，遍历整个account，把每个邮箱和下标的序列放进去，放进去之前先检查一下，如果之前出现过这个邮箱，使用并查集把这俩下标合并。
遍历完了。
```
        bingcha bc = new bingcha(n);
        for(int i=0;i<n;i++) {
            List<String> account = accounts.get(i);
            for(int j=1;j<account.size();j++) {
                String email = account.get(j);
                if(map.containsKey(email)) {
                    int flag = map.get(email);
                    bc.combine(flag,i);
                }
                map.put(email,i);
            }
        }
```
之后干嘛呢，再建立一个Map，这个Map是下标和邮箱集的映射，注意，这个时候已经邮箱去重，邮箱排序，名单去重了。前两者采用TreeSet，后者通过并查集。
```
        Map<Integer,Set<String>> map2 = new HashMap<>();
        for(int i=0;i<n;i++) {
            int index = bc.find(i);
            List<String> account = accounts.get(i);
            List<String> emails = account.subList(1,account.size());
            if(map2.containsKey(index)) {
                map2.get(index).addAll(emails);
            }else{
                map2.put(index,new TreeSet<>(emails));
            }
        }
```
最后是输出答案，把map里面的下表转换成人名，然后放在集合的首位。
```
        for(Map.Entry<Integer,Set<String>> entry :map2.entrySet()) {
            List<String> tmp = new LinkedList<>();
            int index = entry.getKey();
            String name = accounts.get(index).get(0);
            tmp.add(name);
            tmp.addAll(entry.getValue());
            ans.add(tmp);
        }
        return ans;
```
