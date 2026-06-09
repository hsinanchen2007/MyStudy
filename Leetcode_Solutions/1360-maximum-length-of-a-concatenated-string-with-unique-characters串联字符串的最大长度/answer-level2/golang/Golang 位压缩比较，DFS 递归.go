### 解题思路

*   runtime 0ms
*   ram 2MB
*   beats 100% go submits
  
采用了以下两个大佬的思路，使得性能得到显著提高。

感谢 ❤ [花花酱的详细视频讲解](https://zxi.mytechroad.com/blog/searching/leetcode-1239-maximum-length-of-a-concatenated-string-with-unique-characters/)


感谢 ❤ [小小算法的答案解析](https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/solution/jian-ji-de-chui-su-yi-dong-by-huwt/)

因为这两位大佬的算法都是C++写的，我这里在题目的基础上写一个 `Go`的解答。思路和两位大佬提出的答案是一样的。***侵删！***

#### 位压缩的思路

采用位压缩来*查重复*是一种非常快速的计算方法，无需使用map或者其他复杂的数据结构。这里粗鄙的说明一下位压缩。

    因为这道题的字符全是小写英文字符，所以用一个int来做bit mask。

我们可以把一个 `bit mask`看成一个数组，`mask[i]`为`0`表示第`[i]`个位置还没出现，如果为`1`则表示出现了重复。由于全小写字母，所以只需要一个长度为26的mask。在`Go`里面，如果没有特别指出，`int`是64bit。这足够我们当`bit mask`了。

我们设 `'a'` 字符对应 `mask[0]`, 这样对于其他小写字符`x`, `x-a`就是这个字符相对的位置。
    
例如(以一个byte为例）：

    `abc`  对应     `1110 0000`
    `dbc`  对应     `0111 0000`
    `def`  对应     `000d 1100`
    对这两个字符执行 & 操作，如果答案不为0，则说明他们之间有重复。

### 代码

```golang
func maxLength(arr []string) int {
	mask := 0
	return dfs(arr, 0, mask)
}

// isUnique 是用来查看接下来的这个字符串是否含有与之前找到的组合重复。
// 这里的mask 是一个指针，如果不重复，我们需要及时更新这个指针。
// 如果不重复，返回 true。反之，返回 false
func isUnique(s string, mask *int) bool {
	for _, c := range s {
		i := c - 'a'
		if *mask&(1<<i) != 0 {
            // 如果重复，返回false
            return false
        }
        // 不重复的话，我们跟新这个mask用于下一此检查
		*mask |= 1 << i
	}
	return true
}

// max 用来返回int型的最大值，由于标准库的math过大，
// 而且math.Max(float64, float64) float64 的签名使用麻烦。
// 为简单起见，我们自定义一个简单的辅助函数。
func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

// dfs 深度搜索（递归）实现
// 对于输入的字符串数组，我们从某个起始位开始，根据已经获得的mask，
// 来不断就行深度搜索。返回搜索出的最长字符串的长度。
func dfs(arr []string, childIndex int, mask int) int {
    // 已经将数组处理完毕，返回0
    // 递归的 base case
	if childIndex == len(arr) {
		return 0
	}

    // 对于每一次搜索，我们要使用一个新的bit mask
    // 基于 DP 的思想。
	mask2 := mask
    // 我们先判断接下来要处理的字符串与已经获得字符串是否有重复字符。
    // 这里是不含重复字符的案例。
	if isUnique(arr[childIndex], &mask2) {
        // 获得将要处理的字符串长度
        curLen := len(arr[childIndex])
        // len1 是把当前字符串纳入考虑后，继续递归搜索他后面的字符串
        len1 := curLen + dfs(arr, childIndex+1, mask2)
        // len2 是不把当前字符串纳入考虑，继续递归搜索
        len2 := dfs(arr, childIndex+1, mask)
        // 比较 len1 和 len2，就能获得最长字符串
		return max(len1, len2)
	}

    // 如果这个字符串重复，我们跳过塔，继续递归搜索
	return dfs(arr, childIndex+1, mask)
}
```

小结：

*   Go 里面string literal 是utf-8
*   位比较是查询有限字符重复的快速方法