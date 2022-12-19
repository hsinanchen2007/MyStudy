```
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result =new ArrayList<>();
        List<Integer> before = new ArrayList<>();
        List<Integer> behind;
        if (numRows == 0 )
            return result;
        before.add(1); //第一行是一个 [1]
        for (int current =0 ;current < numRows; current++){
            result.add(before);
            behind= before;
            before=new ArrayList<>();
            before.add(1); //每行第一位都是1
            for(int place = 1 ;place<behind.size() ;place++ ){
                before.add(behind.get(place)+behind.get(place-1)); // 中间内容错位加起来
            }
            before.add(1);//每行最后一位也都是1
        }
        return result;
    }
}
```

