```
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> lists = new ArrayList<>();
        
        for(int x=0;x<numRows;x++){
            List<Integer> list = getRow(x+1);
            lists.add(list);
        }
        return lists;
        
    }
    public List<Integer> getRow(int rowIndex) {
        List<Integer> result = new ArrayList<>();

        if (rowIndex<=1){
            for (int x=0;x<rowIndex;x++){
                result.add(1);

            }
            return result;
        }

        List<Integer> row = getRow(rowIndex - 1);
        result.add(1);
        for (int x=0;x<row.size()-1;x++){
            result.add(row.get(x)+row.get(x+1));
        }
        result.add(1);
        return result;

    }
}
```
话不多说，刚从另外一个杨辉三角题目过来，那个是返回第N行，正好那边的代码就在这里拿过来用了
