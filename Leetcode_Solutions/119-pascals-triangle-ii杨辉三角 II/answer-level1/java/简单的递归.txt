```
public List<Integer> getRow(int rowIndex) {
        List<Integer> result = new ArrayList<>();
        
        if (rowIndex==0){
            result.add(1);
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
```
    本身不是特别难的题目，用了递归的思想。
    让我卡了好几次的地方是没有看清题目，题目说了是索引，从0开始。我把它当成了行数，从1开始了

