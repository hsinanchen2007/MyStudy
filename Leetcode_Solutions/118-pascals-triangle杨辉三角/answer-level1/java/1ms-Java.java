### 解题思路
杨辉三角形的特点，后面一行依赖上面一行。

### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> results = new ArrayList<>();
        if (numRows == 0) {
            return results;
        }
        List<Integer> list1 = new ArrayList<>();
        list1.add(1);
        results.add(list1);
        if (numRows == 1) {
            return results;
        }
        List<Integer> list2 = new ArrayList<>();
        list2.add(1);
        list2.add(1);
        results.add(list2);
        for (int i = 2; i < numRows; i++) {
            List tmp = new ArrayList();
            tmp.add(1);
            for (int j = 1; j <= i - 1; j++) {
                tmp.add(results.get(i - 1).get(j - 1) + results.get(i - 1).get(j));
            }
            tmp.add(1);
            results.add(tmp);
        }
        return results;
    }
}
```