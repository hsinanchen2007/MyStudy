### 解题思路
此题和之前一道题考查的类似。
只需要将最后一行输出出来就可以了。
大体思路还是上一题的代码。

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>> lists = new ArrayList<>();

        List<Integer> list = new ArrayList<>();
        list.add(1);
        lists.add(new ArrayList<>(list));

        for(int i = 1; i <= rowIndex; i++){
            List<Integer> l = new ArrayList<>();
            List<Integer> pre = lists.get(i-1);
            l.add(1);

            for(int j = 1; j < pre.size(); j++){
                l.add(pre.get(j-1) + pre.get(j));
            }
            l.add(1);
            lists.add(new ArrayList<>(l));
        }
        return lists.get(rowIndex);
    }
}
```