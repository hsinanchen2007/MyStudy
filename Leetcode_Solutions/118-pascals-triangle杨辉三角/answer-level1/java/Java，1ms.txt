### 解题思路
动态规划

### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> answer = new ArrayList<>();
        if (numRows == 0) {
            return answer;
        }
        List<Integer> row1 = new ArrayList<>();
        row1.add(1);
        answer.add(row1);
        if (numRows == 1) {
            return answer;
        }
        List<Integer> row2 = new ArrayList<>();
        row2.add(1);
        row2.add(1);
        answer.add(row2);
        if (numRows == 2) {
            return answer;
        }
        for (int i = 2; i < numRows; i++) {
            List<Integer> newRow = new ArrayList<>();
            newRow.add(1);
            List<Integer> preRow = answer.get(i-1);
            for (int j = 1; j < i; j++) {
                newRow.add(preRow.get(j-1)+preRow.get(j));
            }
            newRow.add(1);
            answer.add(newRow);
        }
        return answer;
    }
}
```