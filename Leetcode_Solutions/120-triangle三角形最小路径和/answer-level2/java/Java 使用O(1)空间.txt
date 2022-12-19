[2],
[3,4],
[6,5,7],
[4,1,8,3]

自顶向下推算最优

遍历到每一行的时候, 当前index = min(当前index + 上一行index, 当前index + 上一行index - 1) 可以保证每个数据都是最优解

只使用了常数空间res 时间复杂度n^2
```
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle.size() == 0) return 0;
        for(int i = 1; i < triangle.size(); i ++) {
            List<Integer> list = triangle.get(i - 1);
            for(int j = 0; j <= i; j ++) {
                List<Integer> tempList = triangle.get(i);
                if(j - 1 < 0) {
                    tempList.set(j, tempList.get(j) + list.get(j));
                } else if(j == i) {
                    tempList.set(j, tempList.get(j) + list.get(j - 1));
                } else {
                    tempList.set(j, Math.min(tempList.get(j) + list.get(j), tempList.get(j) + list.get(j - 1)));
                }
            }
        }
        List<Integer> tempList = triangle.get(triangle.size() - 1);
        int res = tempList.get(0);
        for(int num: tempList) {
            res = Math.min(num, res);
        }
        return res;
    }
}
```
