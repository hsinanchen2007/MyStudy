```
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        for(int x=1;x<=numRows;x++){
            List<Integer> row = new ArrayList<Integer>();
            for(int j=1;j<=x;j++){
                if(j==1){
                    row.add(1);
                }else if(j==x){
                    row.add(1);
                }else {                    
                    row.add(list.get(x-2).get(j-2)+list.get(x-2).get(j-1));
                }
            }
            list.add(row);
        }
        return list;
    }
}
```
