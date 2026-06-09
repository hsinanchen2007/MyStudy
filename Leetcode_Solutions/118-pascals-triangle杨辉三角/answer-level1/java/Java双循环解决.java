### 解题思路
下一层的数组由上一层的数组构成，index满足条件的时候相加，不满足直接设为1
![image.png](https://pic.leetcode-cn.com/8774fe4b96b141965cfaccfb2b4aff255682dc14b72acdcde61ccde60018fc4b-image.png)


### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
      List<List<Integer>> result = new ArrayList<>();
        if (numRows == 0) return result;

        List<Integer> list = new ArrayList<>(1);
        list.add(1);
        result.add(list);

        for (int i = 1; i < numRows; i++) {
            result.add(gen(result.get(i - 1), i + 1));
        }
        return result;
    }

    private static List<Integer> gen(List<Integer> prev, int num) {
        List<Integer> list = new ArrayList<>(num);
        for (int i = 0; i < num; i++) {
            if (i - 1 >= 0 && i < prev.size()) {
                list.add(prev.get(i) + prev.get(i - 1));
            } else {
                list.add(1);
            }
        }
        return list;
    }
}
```