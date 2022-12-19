### 解题思路
递归在于每个元素的计算，而不是每一行的计算。
非递归在于每一行的计算依赖上一行。

### 递归解法代码

```java
class Solution {
    //递归解法
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        for(int i=0; i<numRows; i++){
            List<Integer> row = new ArrayList<>();
            for(int j=0; j <= i; j++){
                row.add(get(res, i,j));
            }
            res.add(row);
        }
        return res;
    }
    public Integer get(List<List<Integer>> res, int i, int j){
        if(i==0||i==j||j==0){
            return 1;
        }

        //下面3行是递归的优化，保存记忆
        if(res.size()>=i && res.get(i-1).size()>j){
            return res.get(i-1).get(j-1) + res.get(i-1).get(j);
        }
       return get(res, i-1,j-1)+ get(res, i-1,j);
    }
}
```

### 非递归解法代码
```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        if(numRows==0){return new ArrayList<>();}
        List<List<Integer>> result =  new ArrayList<>();
        List<Integer> res =  new ArrayList<>();
        res.add(1);
        result.add(res);
       for(int i = 1; i <= numRows-1; i++){
           result.add(generateNextLine(result,i));
       }
        return result;
    }
    
    public List<Integer> generateNextLine(List<List<Integer>> preResult, int numRows) {
        List<Integer> res =  new ArrayList<>();
        int colNum = numRows;
        res.add(1);
        for(int j = 1; j < colNum; j++){
            res.add(preResult.get(numRows-1).get(j-1)+preResult.get(numRows-1).get(j));            
        }
        res.add(1);

        return res;
    }
    
    
}
```