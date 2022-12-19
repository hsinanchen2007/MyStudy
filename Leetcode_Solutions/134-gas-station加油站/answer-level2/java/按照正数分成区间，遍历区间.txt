执行结果：
通过
显示详情
执行用时 :
4 ms
, 在所有 Java 提交中击败了
41.82%
的用户
内存消耗 :
37.4 MB
, 在所有 Java 提交中击败了
56.84%
的用户
```
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int len = gas.length;
        int[] rem = new int[len];
        int sum=0;
        List<Integer> pos = new ArrayList<Integer>();
        Map<Integer,Integer> map = new HashMap<>();
        int subsum=0;
        for(int i=0; i<len; i++){
            rem[i] = gas[i]-cost[i];
            
            if(rem[i]>=0){
                if(pos.size()>0){
                    map.put(pos.get(pos.size()-1),subsum);
                }
                subsum=0;
                pos.add(i);
            }
            subsum+=rem[i];
            sum+=rem[i];
        }
        if(sum<0)return -1;
        for(int i=0; i<pos.get(0); i++){
            subsum+=rem[i];
        }
        map.put(pos.get(pos.size()-1),subsum);
        
        
        int subsum2=0;
        int res = 0;
        for(int i=0; i<pos.size(); i++){
          // System.out.println(pos.get(i));
            subsum2+=map.get(pos.get(i));
            if(subsum2<0){
                res=pos.get(i+1);
                subsum2=0;
            }
        }
        if(res==0)res=pos.get(0);
        return res;
        
    }
}
```
