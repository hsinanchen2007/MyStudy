![image.png](https://pic.leetcode-cn.com/65e4d6d2dde154bcb6c53f080b2d993493189561724e63a7a4fd83a233b893e5-image.png)


### 解题思路
比较好理解，一次遍历，比较当前和前一个是否相等，不相等时对比下标是否超过3，注意最后一个的边界问题

### 代码

```java
class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> result = new ArrayList<>();
        char[] chars = S.toCharArray();
        int pre = 0;
        for (int i = 1; i <= chars.length; i++) {
            if (i == chars.length || chars[i] != chars[pre]) {
                if (i - pre >= 3) {
                    List<Integer> list = new ArrayList<>(3);
                    list.add(pre);
                    list.add(i - 1);
                    result.add(list);
                }
                pre = i;
            }
        }

        return result;
    }
}
```