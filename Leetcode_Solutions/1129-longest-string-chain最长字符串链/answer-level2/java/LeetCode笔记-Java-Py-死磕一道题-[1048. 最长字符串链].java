#### 1048. 最长字符串链  Medium


##### 方法1：DP

- `dp[i]`表示从`words[0]`到`words[i]`最长的词链长度

> 将字母按字符长度字典序排序的代码

![LeetCode草稿.png](https://pic.leetcode-cn.com/29b6f2144970d4f6e0e7882cd34c9251f6cf4c8d2d55654efcd2caf92fadd23d-LeetCode%E8%8D%89%E7%A8%BF.png)

```java
      Arrays.sort(words, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.length() - o2.length();
            }
        });
```




```java []
public int longestStrChain(String[] words) {
    Arrays.sort(words, Comparator.comparingInt(String::length));
    int n = words.length;
    int[] dp = new int[n];
    int res = 0;
    for (int i = 0; i < n; i++) {
        String a = words[i];
        for (int j = i + 1; j < n; j++) {
            String b = words[j];
            if (isPredecessor(a, b)) {
                dp[j] = Math.max(dp[j], dp[i] + 1);
                res = Math.max(dp[j], res);
            }
        }
    }
    return res + 1;
}

/**
 * 判断a是否是b的前身 是返回true 如 "bda" 是"bdca"的前身
 *
 * @param a
 * @param b
 * @return
 */
private boolean isPredecessor(String a, String b) {
    int i = 0, j = 0;
    int m = a.length(), n = b.length();
    if ((m + 1) != n) return false;
    while (i < m && j < n) {
        if (a.charAt(i) == b.charAt(j)) i++;
        j++;
    }
    return i == m;
}
```
```python []
print('Hello world!')
```





##### 方法2：改进版DP

- 根据题意`1 <= words[i].length <= 16` ==>`arr`存放的是`17`个长度的辅助数组，存的是`words`的同一字符长度的最末的下标
- `dp[i]`表示从`words[0]`到`words[i]`最长的词链长度

![clipboard.png](https://pic.leetcode-cn.com/21ffeb94964cdc0169e98d99ac384d798e22d51ddb9567379335c7e052f9d267-clipboard.png)

![f7a6c42a3edf37751377413c52727ea.jpg](https://pic.leetcode-cn.com/c9d682e5270d99bab28ab3c5b99e0bfbff7c6d86e2c52f76e110dd090ce2c9b1-f7a6c42a3edf37751377413c52727ea.jpg)

```java []
public int longestStrChain1st(String[] words) {
    Arrays.sort(words, Comparator.comparingInt(String::length));
    int[] arr = new int[17];
    Arrays.fill(arr, -1);
    int n = words.length;
    for (int i = 0; i < n; i++) {
        arr[words[i].length()] = i;
    }
    int[] dp = new int[n];
    Arrays.fill(dp, 1);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int target = words[i].length() - 1;
        int index = arr[target];
        while (index >= 0 && words[index].length() == target) {
            if (isPredecessor(words[index], words[i])) {
                dp[i] = Math.max(dp[i], dp[index] + 1);
            }
            index--;
        }
        res = Math.max(dp[i], res);
    }
    return res;
}
```
```python []
print('Hello world!')
```





##### 方法3：DFS
```java []
int res = 0;

public int longestStrChain2nd(String[] words) {
    int min = 0, max = 16;//最小字符长度，最大字符长度
    //K为字符长度，Set为该字符长度的word集合
    Map<Integer, Set<String>> map = new HashMap<>();
    for (String word : words) {
        map.putIfAbsent(word.length(), new HashSet<>());
        map.get(word.length()).add(word);
        min = Math.min(min, word.length());
        max = Math.max(max, word.length());
    }
    for (int len = min; len <= max; len++) {
        Set<String> curSet = map.get(len);
        if (curSet == null) continue;//当set没有值时，无需遍历
        if ((max + 1 - len <= res)) continue;//最大长度+1-当前的长度<=res，res更加符合题意
        for (String cur : curSet) {
            findNext(map, len, cur);
        }
    }
    return res;
}

/**
 * @param map
 * @param len 当前字符的长度
 * @param levelStr 当前字符
 */
private void findNext(Map<Integer, Set<String>> map, int len, String levelStr) {
    res = Math.max(res, levelStr.length() + 1 - len);//记录结果集
    Set<String> curSet = map.get(levelStr.length() + 1);//
    if (curSet == null) return;//退出条件
    Iterator<String> it = curSet.iterator();
    while (it.hasNext()) {
        String next = it.next();
        if (isPredecessor(levelStr, next)) {
            findNext(map, len, next);
            it.remove();
        }
    }
}
```
```python []
print('Hello world!')
```

