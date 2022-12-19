### 思路

- 示例：`))(()())(())((`
- 遍历并寻找中心 `c`
- 以 `left = c, right = c + 1` 进行中心扩展，内部 **递归寻找** 最左边能到达的索引

<![image.png](https://pic.leetcode-cn.com/16e0aaf6eb7722263128b377194a8972182b3da3b7b5600eae9487cc392bbee1-image.png), ![image.png](https://pic.leetcode-cn.com/d144694347c4429f1397ccabd1a817b8e4c1a82c3bd335c8162068c57e162bea-image.png), ![image.png](https://pic.leetcode-cn.com/7c380e2ccda6cf905a9e9fddc91a12676b8d7f6475d58df036e343fdac4424e2-image.png)>




### 代码

```java
// (right, left)
private Map<Integer, Integer> map = new HashMap<>();
// key: 右括号的索引, value: 对应左括号的索引

public int longestValidParentheses(String s) {
    char[] arr = s.toCharArray();
    int max = 0;
    // 遍历中心
    for (int c = 0; c < arr.length - 1; c++) {
        if (arr[c] == '(' && arr[c + 1] == ')') {
            int r = expand(arr, c, c + 1);
            max = Math.max(max, r - map.get(r) + 1);
            c = r;
        }
    }
    return max;
}

// 中心扩展
private int expand(char[] arr, int l, int r) {
    while (l >= 0 && r < arr.length && arr[l] == '(' && arr[r] == ')') {
        l--; r++;
    }
    if (map.containsKey(l)) return expand(arr, map.get(l) - 1, r); // 继续递归扩展
    map.put(r - 1, l + 1); // (右, 左)
    return r - 1;
}
```

### 复杂度分析

- 空间复杂度 $O(n)$
  - 不计递归占用的话，主要是 `char[] arr` 的内存空间
- 时间复杂度 $O(n)$
  - 虽然看起来是 `for` 内再 `while` 又 `expand` 递归，但从看大局 `c` 也在不断右移
    - 并没有浪费左移的重复时间