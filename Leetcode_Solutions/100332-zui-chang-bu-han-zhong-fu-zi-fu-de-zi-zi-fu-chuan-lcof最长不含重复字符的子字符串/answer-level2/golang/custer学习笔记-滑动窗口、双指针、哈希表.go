### 解题思路
使用滑动窗口，同样使用双指针i和j区别是它们只向前移动，

这里我们还需要一个哈希表count记录出现过的字符的次数。

同时需要maxLength来记录最大长度，把它初始化为0，i和j都从0开始，

- 当j指向的字符没有出现在count中，则继续移动j并把该字符和出现的次数记录在count中，
- 当j指向的字符出现在count中，则记录没有重复字符的子串长度j-i
- 然后和当前maxLength对比，用较大的值更新maxLength。
- 接下来因为i和j中已经有重复字符了，我们移动i，并且把i指向的字符a在count中数量-1.
- i移动到了新的位子之后，j继续上面一样的过程即可。

这样操作结束后，maxLength保存的就是不包含重复字符的最大子串长度，

这里i和j不断向前移动，总共移动了2n次。时间复杂度是O(n)。

### 代码

```golang
// Time: O(n), Space: O(m), m 是字符集大小
func lengthOfLongestSubstring(s string) int {
  // 定义一个记录字符出现次数的哈希表
  // 这里字符就是ASCII字符，大小为256的int数组代替即可
  counts := make([]int, 256)
  // 如果字符集比ASCII大得多，可以直接用一个hashmap来替代这个int数组即可。
  // 定义滑动窗口左右指针i和j，最大长度值maxLength
  i, j, maxLength := 0, 0, 0
  // 这里使用两层for循环
  for ; i < len(s); i++ { // 不过注意内层循环不会每次都从0开始
    for ; j < len(s); j++ { // 而是不断向前移动
      if counts[s[j]] != 0 { // 如果j指向的字符已经出现过
        break // 则内循环结束
      }
      // 否则为当前字符在counts数组中出现的次数+1
      counts[s[j]]++
    }
    // 内层循环结束时更新maxLength
    // j-i表示当前不包含重复字符的子串长度
    if maxLength < j-i {
      maxLength = j - i
    }
    // 在i向前移动前，把i指向的字符数量-1
    counts[s[i]]--
  }
  // 两层循环结束后返回maxLength即可。
  return maxLength
}
```

### 解题思路
是上面方法的优化版本，我们演示一个例子字符串为abcbadfe

当i在a这里，j在b这里，开始出现重复的字符b，上面的方法是把i移动到下一个位置b，

然而这一步做了无用功，因为这个时候子串bcb还是有重复的字符，

所以这里可以优化的点是，i不是一步步移动，而是直接移动到重复字符的下一位。

这里就是直接移动到c。这种方法j还是移动了n次，但i的移动次数就大大减少了，时间复杂度是O(n）

### 代码

```golang
// Time: O(n), Space: O(m), m 是字符集大小
func lengthOfLongestSubstring(s string) int {
  // index数组记录字符出现的下标
  index := make([]int, 256)
  // 数组默认初始化为0，但0是一个有意义的下标
  // 于是在算法开始前，把它们都初始化为-1
  for i := range index {
    index[i] = -1 // 并把它们初始化为-1
  }
  maxLength := 0 // 定义最后的结果长度为maxLength
  for i, j := 0, 0; j < len(s); j++ {
    // 首先更新i的值,如果j指向的字符已经出现过
    // 那i有可能直接跳到这个出现字符的下一位
    // 也有可能保持不变仍然是i这里取较大的一个
    if index[s[j]]+1 > i {
      i = index[s[j]] + 1
    }
    // 接下来更新maxLength
    // j-i+1表示的是当前不包含重复字符的子串长度
    // 这里的j指向的字符是包含在子串中，所以要+1
    if j-i+1 > maxLength {
      maxLength = j - i + 1
    }
    // 最后把j指向的字符和j保存起来
    index[s[j]] = j
  }
  return maxLength // 最后返回maxLength即可
}


```