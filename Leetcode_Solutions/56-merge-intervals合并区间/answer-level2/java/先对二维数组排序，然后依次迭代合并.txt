执行结果：
通过
显示详情
执行用时 :
16 ms
, 在所有 Java 提交中击败了
74.01%
的用户
内存消耗 :
43.7 MB
, 在所有 Java 提交中击败了
67.21%
的用户
```
class Solution {
    public int[][] merge(int[][] intervals) {
        int m = intervals.length;
        if(m<2)return intervals;
        Map<Integer,Integer> map = new TreeMap<Integer,Integer>();
        for(int i=0; i<m; i++){
            if(map.get(intervals[i][0])!=null){
               // System.out.println("ddd"+intervals[i][0]+"-"+intervals[i][1]+"-"+map.get(intervals[i][0]));
                if(intervals[i][1]>map.get(intervals[i][0])){
                    // System.out.println("ccc"+intervals[i][0]+"-"+intervals[i][1]+"-"+map.get(intervals[i][0]));
                    map.put(intervals[i][0],intervals[i][1]);
                }
            }else{
                map.put(intervals[i][0],intervals[i][1]);
            }
            
        }
        //print(map);
        
        int[][] res = new int[m][2];
        int j=0;
        boolean first = true;
        Iterator<Map.Entry<Integer,Integer>> it = map.entrySet().iterator();
        while(it.hasNext()){
            Map.Entry<Integer,Integer> entry = it.next();
            int kk = entry.getKey();
            int vv = entry.getValue();
            if(first){
                res[j][0]=kk;
                res[j][1]=vv;
                first=false;
            }else if(kk<=res[j][0]&&vv>=res[j][0]||kk<=res[j][1]&&vv>=res[j][1]){
                if(kk<res[j][0])res[j][0]=kk;
                if(vv>res[j][1])res[j][1]=vv;
            }else if(kk>res[j][1]||vv<res[j][0]){
                j++;
                res[j][0]=kk;
                res[j][1]=vv;
            }
        }
        int[][] rr = new int[j+1][2];
        for(int i=0; i<j+1; i++){
            rr[i][0]=res[i][0];
            rr[i][1]=res[i][1];
        }
        return rr;
    }
    private void print(Map<Integer,Integer> map ){
        Iterator<Map.Entry<Integer,Integer>> it = map.entrySet().iterator();
        while(it.hasNext()){
            Map.Entry<Integer,Integer> entry = it.next();
            int kk = entry.getKey();
            int vv = entry.getValue();
            System.out.println(kk+"-"+vv);
        }
    }
}
```
