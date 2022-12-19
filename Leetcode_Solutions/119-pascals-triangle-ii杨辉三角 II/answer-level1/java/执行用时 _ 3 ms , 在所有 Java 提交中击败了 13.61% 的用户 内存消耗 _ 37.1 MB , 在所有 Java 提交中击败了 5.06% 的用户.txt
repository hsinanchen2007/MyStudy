### 解题思路
和上一道杨辉三角类似，但需要改变一些条件，由于是取第K行，但本题由第0行起算，所以实际是第四行，我们想取到该行需要把row<=rowindex,否则取不到第K行。

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        list.add(new ArrayList<Integer>());
        list.get(0).add(1);
        for(int row = 1;row<=rowIndex;row++) {
            List<Integer> sublist = new ArrayList<Integer>();
            List<Integer> prev = list.get(row-1);
            sublist.add(1);
            for(int i = 1;i<row;i++) {
                sublist.add(prev.get(i-1)+prev.get(i));
            }
            sublist.add(1);
            list.add(sublist);
        }
        return list.get(rowIndex);
    }
}
```