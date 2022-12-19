```
//45 ms
class Solution {
    public int[] bestLine(int[][] points) {
        map = new LinkedHashMap<>();
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i < points.length-1; ++i){
            for(int j = i+1; j < points.length; ++j){
                int diffx = points[j][0] - points[i][0];
                int diffy = points[j][1] - points[i][1];
                double k = compute(diffx, diffy);
                List<Integer> list;
                if(map.get(k) == null){
                    list = new ArrayList<>();
                    list.add(i);
                    list.add(j);
                    map.put(k, list);
                }else{
                    list = map.get(k);
                    list.add(j);
                    map.put(k, list);
                }
                if(list.size() > res.size()){
                    res = list;
                }
            }
            map = new LinkedHashMap<>();
        }
        return new int[]{res.get(0), res.get(1)};
    }
    private HashMap<Double, List<Integer>> map;
    private double compute(int diffx, int diffy){
        if(diffx == 0){
            return -12345.0;
        }else if(diffy == 0){
            return 0.0;
        }else{
            return (double)diffy / (double)diffx;
        }
    }
}
```
