### 解题思路
[Leetcode-Java(240+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_118_generate.java)

### 代码

```java
class Solution {
    /**
     * 解题思路：
     * 0、用一个list数组保存上一行的遍历结果
     * 1、当下一行是头和尾，直接赋值1
     * 2、当下一行在中间位置j，结果=preItem.get(j - 1) + preItem.get(j)
     * @param numRows
     * @return
     */
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> retList = new ArrayList<>();
        List<Integer> preItem = null;
        for (int i = 0; i < numRows; i++) {
            List<Integer> item = new ArrayList<>();
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    item.add(1);
                } else {
                    item.add(preItem.get(j - 1) + preItem.get(j));
                }
            }
            preItem = item;
            retList.add(item);
        }
        return retList;
    }
}
```