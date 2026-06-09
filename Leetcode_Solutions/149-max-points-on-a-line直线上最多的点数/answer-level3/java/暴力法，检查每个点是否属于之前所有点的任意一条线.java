执行结果：
通过
显示详情
执行用时 :
111 ms
, 在所有 Java 提交中击败了
9.95%
的用户
内存消耗 :
43.6 MB
, 在所有 Java 提交中击败了
31.69%
的用户
```
class Solution {
    public int maxPoints(int[][] points) {
        if(points.length==0)return 0;
        Map<Integer,Map<Integer[],Integer>> map = new HashMap<>();
        Map<Integer,Integer> dup = new HashMap<>();
        boolean found=false;
        for(int k=0; k<points.length; k++){
            int[] i = points[k];
            for(Integer ii:map.keySet()){
                if(i[0]==points[ii][0]&&i[1]==points[ii][1]){
                    dup.put(ii,dup.getOrDefault(ii,0)+1);
                }
                else{
                    Integer[] iarr = new Integer[]{(i[1]-points[ii][1]),(i[0]-points[ii][0])};
                    found=false;
                    for(Integer[] earr:map.get(ii).keySet()){
                        if((long)iarr[0]*earr[1]==(long)iarr[1]*earr[0]){
                            found=true;
                            map.get(ii).put(earr,map.get(ii).getOrDefault(earr,0)+1);
                        }
                    }
                    if(!found)map.get(ii).put(iarr,1);//如果不属于这个点已知的任意一条线，则加入一条新线
                }
            }
            Map<Integer[],Integer> sub = new HashMap<>();
            map.put(k,sub);
        }
        
        int max2 = 0;
        for(Integer ii:map.keySet()){
            int max=0;
            for(Integer m:map.get(ii).values()){
                if(m>max)max=m;
            }
            int vv=max+dup.getOrDefault(ii,0);
            if(vv>max2)max2=vv;
        }
        max2++;
        
        return max2;
    }
}
```
