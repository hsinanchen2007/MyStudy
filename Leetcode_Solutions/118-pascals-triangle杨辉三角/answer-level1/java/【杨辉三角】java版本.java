### 解题思路
1、第一行只有1，直接添加
2、每行的第一个元素和最后一个元素均为1，直接添加
3、每行（i行）中间元素值（index=j）=上一行（i-1行）（index=j-1）的值+（index=j）的值

### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        if (numRows == 0) return result;
        //先添加第一行
        result.add(Collections.singletonList(1));
        for (int i = 1; i < numRows; i++) {
            List<Integer> list = new ArrayList<>();
            //添加第一个1
            list.add(1);
            for (int j = 1; j < i; j++) {
                list.add(result.get(i - 1).get(j - 1) + result.get(i - 1).get(j));
            }
            //添加最后一个1
            list.add(1);
            result.add(list);
        }
        return result;
    }
}
```