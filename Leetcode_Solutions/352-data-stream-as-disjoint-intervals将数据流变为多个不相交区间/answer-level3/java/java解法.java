```
class SummaryRanges {
    List<int[]> list;
    Set<Integer> set;
    /** Initialize your data structure here. */
    public SummaryRanges() {
        list = new ArrayList<>();
        set = new HashSet();
    }
    
    public void addNum(int val) {
        if(set.contains(val)){
            return;
        }
        set.add(val);
        for(int i = 0; i < list.size(); i++){
            if(list.get(i)[0] > val){
                if(list.get(i)[0] == val+1){
                    list.get(i)[0] =val;
                }else{
                    int[] o = new int[]{val,val};
                    list.add(i, o);
                }
                return;
            }
            if(list.get(i)[1] > val){
                return;
            }
            if(list.get(i)[1] == val - 1){
                list.get(i)[1] = val;
                if(i < list.size()-1 && list.get(i+1)[0] == val+1){
                    list.get(i+1)[0] = list.get(i)[0];
                    list.remove(i);
                }
                return;
            }
        }
        if(list.size()>0 && list.get(list.size()-1)[1] == val-1){
            list.get(list.size()-1)[1] = val;
        }else{
            int[] o = new int[]{val,val};
            list.add(o);
        }
    }
    
    public int[][] getIntervals() {
        int[][] res = new int[list.size()][];
        for(int i = 0; i < list.size(); i++){
            res[i] = list.get(i);
        }
        return res;
    }
}
```
