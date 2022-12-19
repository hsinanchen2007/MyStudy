### 解题思路
- 利用一个数组，循环更新当前行，节省空间
- 按照倒序添加元素，这样利用上一行的第j-1和j更新当前行的j,再利用上一行的j-2和j-1更新当前行的j-1。相对于正序添加，节省了一个temp空间。

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> res = new ArrayList<>();
        //初始化第0行
        res.add(1);
        //不新建列表 而是不断更新覆盖res 节省空间
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i - 1; j > 0; j--) {
                res.set(j,res.get(j-1) + res.get(j));
            }
            res.add(1);
        }
        return res;
    }
}
```