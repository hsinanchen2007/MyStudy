对于这个题来说，可以用DFS来解决。DFS即`Depth first search`，深度优先遍历，这是在树中所必学的一个遍历方式。

对于本题来说，我们也可以把这个List当做一个树，因为每一个元素都有两种遍历方式，即比较或者不比较，用题目中的例子来说：`["cha", "r", "act", "ers"]`，它所派生出的二叉树如下：

![二叉树.png](https://pic.leetcode-cn.com/636b9bef729be69730059189407c91e932105ecc3bd0c24e5946edce56c62f1b-%E4%BA%8C%E5%8F%89%E6%A0%91.png)


按照上面的例子，一共有16中情况，DFS流程为：

- 从第一个字符串开始遍历
  - 两种情况，第一种是加入第一个字符串
  - 第二种是不要第一个字符串
- 遇到第二个字符串，比较第一个字符串和第二个字符串是否有相同的字符
- 如果相同，跳过第二个字符，如果不同，把第二个字符加入
- 如果字符串到达List的最后一个，结束。否则，跳转到第一步

```java
    int maxLen = 0;
    public int maxLength(List<String> arr) {
        dfs(arr, 0, 0, 0);
        return maxLen;
    }
    private void dfs(List<String> arr, int index, int ck, int tempMax) {
        if (index == arr.size()) {
            maxLen = Math.max(maxLen, tempMax);
            return;
        }
        String str = arr.get(index);
        int tempCk = getCk(ck, str);
        if (tempCk != -1) dfs(arr, index + 1, tempCk, tempMax + str.length());
        dfs(arr, index + 1, ck, tempMax);
    }
    // 比较str和之前ck代表的字符串是否有相同字符，如果没有，则把str代表的ck加去，如果有，则返回-1
    private int getCk(int ck, String str) {
        char[] chars = str.toCharArray();
        for(char c: chars) {
            int tempInt = c - 'a';
            if ((ck & (1 << tempInt)) != 0) {
                return -1;
            }
            ck = ck | (1 << tempInt);
        }
        return ck;
    }
```

说句题外话，查看两个字符串（只含有小写字符）是否有相同字符的方法：

1. 使用一个一维数组，遍历两边字符串。空间复杂度O(1)，时间复杂度O(n)

   ```java
       private boolean notEqual(String a, String b) {
           int[] charArray = new int[30];
           for (int i = 0; i < a.length(); i ++) {
               charArray[a.charAt(i) - 'a'] = 1;
           }
           for (int i = 0; i < b.length(); i ++) {
               if (charArray[b.charAt(i) - 'a'] == 1) {
                   return false;
               }
           }
           return true;
       }
   ```

2. 使用位运算：`ck & (1 << i) == 0` 

   其中，ck是一个最少26byte的字符，从左至右，每一位分别代表a,b,,,x,y,x

   i代表字符串中的字符

   ```java
       // 比较str和之前ck代表的字符串是否有相同字符，如果没有，则把str代表的ck加去，如果有，则返回-1
       private int notEqual(int ck, String str)) {
           char[] chars = str.toCharArray();
           for(char c: chars) {
               if (ck & 1 << (a - 'a')) != 0) {
                   return -1;
               }
               ck = ck | 1 << (a - 'a');
           }
           return ck;
       }
   ```





