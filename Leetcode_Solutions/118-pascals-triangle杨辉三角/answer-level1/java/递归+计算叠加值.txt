### 解题思路
代码和注释写的很清楚了，直接参考即可

### 代码

```java
class Solution {
    // 解题思路，递归+组合计算
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> rs = new LinkedList<>();
        if(numRows == 0){
            return rs;
        }
        // 第一个返回1
        if(numRows == 1){
            List<Integer> row = new LinkedList<>();
            row.add(1);
            rs.add(row);
            return rs;
        }
        // 生成n-1的杨辉三角
        rs = generate(numRows-1);
        // 计算本行额外的一行
        List<Integer> extraRow = new LinkedList<>();
        // 左侧加1个1
        extraRow.add(1);
        // 叠加计算数值
        List<Integer> tmpValues = calcOverlapValue(rs.get(rs.size()-1));
        // 如果元素是第2行，无法计算，超过第2行才可以计算叠加
        if(tmpValues != null){
            extraRow.addAll(tmpValues);
        }
        // 右侧加1个1
        extraRow.add(1);
        // 结果加1行
        rs.add(extraRow);
        return rs;
    }

    // 计算叠加值
    private List<Integer> calcOverlapValue(List<Integer> integers) {
        if(integers.size() <= 1){
            return null;
        }
        List<Integer> values = new LinkedList<>();
        for(int i=0;i<integers.size()-1;i++){
            values.add(integers.get(i)+integers.get(i+1));
        }
        return values;
    }
}
```