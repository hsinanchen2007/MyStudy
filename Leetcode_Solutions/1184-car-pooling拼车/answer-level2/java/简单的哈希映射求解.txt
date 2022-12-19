一个Map(上车点，上车人数)，一个Map(下车点，下车人数)。然后for循环整个路程，在每个下车点减下车的人数，每个上车点加上车的人数，期间如果总人数大于capacity，返回false，否则返回true。
```
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        Map<Integer,Integer> start=new HashMap<>();
        Map<Integer,Integer> end=new HashMap<>();
        //min———max：整个行驶区间
        int max=trips[0][2],min=trips[0][1];
        for(int [] t:trips){
            //遇到上车点或者下车点相同，把它们的人数相加即可
            start.put(t[1],start.getOrDefault(t[1],0)+t[0]);
            end.put(t[2],end.getOrDefault(t[2],0)+t[0]);
            min=Math.min(min,t[1]);
            max=Math.max(max,t[2]);
        }
        int cur=0; //现在车上的人数
        for(int i=min;i<=max;i++){
            if(end.containsKey(i))
                cur-=end.get(i);
            if(start.containsKey(i))
                cur+=start.get(i);
            if(cur>capacity)
                return false;
        }
        return true;
    }
}
```
