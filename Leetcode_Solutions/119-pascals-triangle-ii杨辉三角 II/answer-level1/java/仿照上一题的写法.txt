### 解题思路
仿照上一题的思路，当杨辉三角到达目标行数时，直接打印改行即可

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
               List<List<Integer>> lists = new ArrayList<>();

        lists.add(new ArrayList<>());
        lists.get(0).add(1);
    
        for (int i = 1; i <= rowIndex; i++) {
            List<Integer> now = new ArrayList<>();
            List<Integer> pre = lists.get(i-1);
            now.add(1);
            for (int j = 1; j < i; j++) {
                now.add(pre.get(j-1)+pre.get(j));
            }
            now.add(1);
            lists.add(now);
            if (i == rowIndex){
                return now;
            }
        }
        return lists.get(0);
    }
}
```