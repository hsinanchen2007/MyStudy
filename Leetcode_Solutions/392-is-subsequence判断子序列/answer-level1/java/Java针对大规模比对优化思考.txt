### 解题思路

这个解法主要是对后续挑战中大规模比对进行的，首先在初始化时讲T系列通过`getSourceMap`转换为一个表（字母：字母在T中位置列表）。

执行判断时，根据当前字母和当前位置`index`，在map中查找大于index的该字母的位置，能找到就继续，否则返回`false`。

其中`getIndex`还有两个优化点：

1. 使用二分查找法进一步提升查找性能
2. 通过一个位置记录表，记录某个字母现在已经查找过的位置，加速二分查找过程

![image.png](https://pic.leetcode-cn.com/eb3ebc5a1c493797cb0ccb2a4f39fd5de7c23d39dd5807a9b9cc03ce0bb65140-image.png)


### 代码

```java
class Solution {
    private int[][] getSourceMap(String t) {
        // 计算字符数量
        int[] counter = new int[26];
        for (char tt : t.toCharArray()) {
            counter[tt - 'a'] += 1;
        }
        // 初始化map
        int[][] map = new int[26][];
        for (int i = 0; i < counter.length; i++) {
            map[i] = new int[counter[i]];
            counter[i] = 0;
        }
        // 插入map数据
        for (int i = 0; i < t.length(); i++) {
            int index = t.charAt(i) - 'a';
            map[index][counter[index]] = i;
            counter[index] += 1;
        }
        return map;
    }

    private int getIndex(int[] ints, int index) {
        // 这部分查找可以用二分法，提高效率
        for (int i : ints) {
            if (i > index) {
                index = i;
                break;
            }
        }
        return index;
    }

    public boolean isSubsequence(String s, String t) {
        int[][] map = getSourceMap(t);

        int index = -1;
        for (char ss : s.toCharArray()) {
            int ii = index;
            index = getIndex(map[ss - 'a'], index);
            if (index == ii) {
                return false;
            }
        }
        return true;
    }
}
```