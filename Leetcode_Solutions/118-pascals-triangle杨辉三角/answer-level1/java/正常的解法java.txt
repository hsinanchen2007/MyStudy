感觉这个题。。。。。。没有什么可以节省时间的地方啊！
```
public List<List<Integer>> generate(int numRows) {

        List<List<Integer>> res = new ArrayList<>();
        if (numRows == 0){
            return res;
        }
        List<Integer> first = new ArrayList<>();
        first.add(1);
        res.add(first);
        for (int i = 1; i < numRows; i++) {
            List<Integer> e = new ArrayList<>();
            List<Integer> preRowres = res.get(i-1);
            for (int j = 0; j <= i ; j++) {
               if (j == 0 || j == i){
                   e.add(1);
               }else{
                   e.add(preRowres.get(j) + preRowres.get(j-1));
               }
            }
            res.add(e);
        }
        return res;
    }
```
