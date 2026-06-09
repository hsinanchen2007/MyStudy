前面的方法都聊的很好的，我只说一点：

```
${Math.min(dominoes[i][0], dominoes[i][1])}${Math.max(dominoes[i][0], dominoes[i][1])}

作者：jsliang
链接：https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/solution/jsiang-1128-deng-jie-duo-mi-nuo-gu-pai-dui-de-shu-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

通过最小和最大来记录哈希表的key 确实很好，但如果这里题目改一下：

dominoes[i][j] 可以取字符 而不单纯局限于数字

那么这招就没有用了

我的解法是兼容了字符的，效率如下：
执行用时 :80 ms, 在所有 JavaScript 提交中击败了91.07%的用户
内存消耗 :43.9 MB, 在所有 JavaScript 提交中击败了30.77%的用户


```
var numEquivDominoPairs = function(dominoes) {
  if (!dominoes.length) {
      return 0
  }
  var result = 0
  var hashMap = {}

  // 1 -> 0
  // 2 -> 1
  // 3 -> 3
  // 4 -> 6
  // 5 -> 10
  // n -> Σ(n-1) -> n * (n - 1) / 2
  for (var i = 0; i < dominoes.length; i++) {
    var stone = dominoes[i]
    var [A, B] = stone
    var key1 = A + ',' + B
    var key2 = B + ',' + A
    if (hashMap[key1]) {
        hashMap[key1] += 1
    } else {
        hashMap[key1] = 1
    }

    if (hashMap[key2]) {
        hashMap[key2] += 1
    } else {
        hashMap[key2] = 1
    }
  }

  for (var key in hashMap) {
    var num = hashMap[key]
    var A = key.charAt(0)
    var B = key.charAt(2)
    var reverseKey = B + ',' + A

    if (A !== B && hashMap[reverseKey]) {
        result += ((num * (num - 1)) / 2)
        hashMap[reverseKey] = 0
    }

    // 如果只有一个前后相同的元组
    if (A === B && num > 2) {
        var half = num / 2
        result += ((half * (half - 1)) / 2)
    }
  }
  hashMap = null
  return result
};
```
