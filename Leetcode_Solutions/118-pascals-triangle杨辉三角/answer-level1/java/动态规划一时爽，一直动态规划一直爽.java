### 解题思路
动态规划一时爽，一直动态规划一直爽

### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> memo = new ArrayList<>();
        //初始化特殊值
        for (int i = 0; i < numRows; i++) {
            ArrayList<Integer> list = new ArrayList<>();
            list.add(1);
            if (i == 1)
                list.add(1);
            memo.add(list);
            if (numRows == 1)
                return memo;
            if (numRows == 2 && i == 1)
                return memo;
        }


        //规律值赋值
        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < i; j++)
                memo.get(i).add(memo.get(i - 1).get(j - 1) + memo.get(i - 1).get(j));
            memo.get(i).add(1);
        }
        return memo;
    }
}
```