### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> res = new ArrayList<>();

        res.add(1);
        if (rowIndex == 0) return res;
        res.add(1);
        if (rowIndex == 1) return res;


        for (int i = 2; i <= rowIndex; i++) {
            res.add(1);
            for (int j = res.size() - 2; j > 0; j--) {
                res.add(j, res.get(j - 1) + res.remove(j));
            }
        }

        return res;
    }
}
```