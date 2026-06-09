
```
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<>();
        for(int i = 0; i < numRows; i++) {
            List<Integer> list = new ArrayList<>();
            list.add(1);
            triangle.add(list);
            for(int j = 0; j < i - 1; j++) {
            // 获取上一行的相邻两值
                list.add(triangle.get(i - 1).get(j) + triangle.get(i - 1).get(j + 1));
            }
            // 排除第一行
            if(i > 0) {
                triangle.get(i).add(1);
            }
        }
        return triangle;
    }
}


代码块
```
    