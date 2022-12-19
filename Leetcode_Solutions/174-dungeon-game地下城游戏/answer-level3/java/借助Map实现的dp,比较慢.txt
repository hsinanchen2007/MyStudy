执行结果：
通过
显示详情
执行用时 :
95 ms
, 在所有 Java 提交中击败了
15.03%
的用户
内存消耗 :
53.2 MB
, 在所有 Java 提交中击败了
5.04%
的用户
```
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int res = 0;
        int x = dungeon.length;
        if(x==0)return res;
        int y = dungeon[0].length;
        //key=当前总和，value=需要的最小值
        TreeMap<Integer,Integer>[][] dpm = new TreeMap[x+1][y+1];

        for(int i=1; i<=x; i++){
           for(int j=1; j<=y; j++){
                if(i==1&&j==1){
                    int xx=dungeon[0][0];
                    int yy=1;
                    if(xx<=0){
                        yy=xx*-1+1;
                    }
                    dpm[1][1]=new TreeMap<Integer,Integer>();
                    dpm[1][1].put(xx,yy);
                }else{
                    dpm[i][j]=new TreeMap<Integer,Integer>();
                    if(dpm[i-1][j]!=null){
                        for(Map.Entry<Integer,Integer> entry : dpm[i-1][j].entrySet()){
                            int xx = dungeon[i-1][j-1]+entry.getKey();
                            int yy = entry.getValue();
                            if(xx*-1+1>yy){
                                yy=xx*-1+1;
                            }
                            dpm[i][j].put(xx,yy);
                        }
                    }
                    if(dpm[i][j-1]!=null){
                        for(Map.Entry<Integer,Integer> entry : dpm[i][j-1].entrySet()){
                            int xx = dungeon[i-1][j-1]+entry.getKey();
                            int yy = entry.getValue();
                            if(xx*-1+1>yy){
                                yy=xx*-1+1;
                            }
                            dpm[i][j].put(xx,yy);
                        }
                    }
                    
                    //remove those not good.
                    Integer xx=null;
                    Integer yy=null;
                    Iterator<Map.Entry<Integer,Integer>> it = dpm[i][j].entrySet().iterator();
                    
                    //从大到小排列，可以及时break循环
                    //key=需要的最小值，value=当前总和
                    Map<Integer,Integer> pre = new TreeMap<>(new Comparator<Integer>() {

                        @Override
                        public int compare(Integer o1, Integer o2) {
                            return o2.compareTo(o1);
                        }

                    });
                    Set<Integer> toremove = new HashSet<Integer>();
                    while(it.hasNext()){
                        Map.Entry<Integer,Integer> entry = it.next();
                        if(pre.isEmpty()){
                            pre.put(entry.getValue(),entry.getKey());
                        }else{
                            Iterator<Map.Entry<Integer,Integer>> it2 = pre.entrySet().iterator();
                            while(it2.hasNext()){
                                Map.Entry<Integer,Integer> entry2 = it2.next();
                                
                                if(entry.getValue()<=entry2.getKey()){
                                    toremove.add(entry2.getValue());
                                    it2.remove();
                                }else{
                                    break;
                                }
                            }
                            pre.put(entry.getValue(),entry.getKey());
                        }
                    }
                    for(Integer tt:toremove){
                        dpm[i][j].remove(tt);
                    }
                }
            } 
        }
        res=Integer.MAX_VALUE;
        for(Integer ii : dpm[x][y].values()){
                if(ii<res)res=ii;
        }
        return res;
    }
}
```
