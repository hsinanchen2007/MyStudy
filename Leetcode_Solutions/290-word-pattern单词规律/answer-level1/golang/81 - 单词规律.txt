# 81 - 单词规律

## 题目

给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

> 输入: pattern = "abba", str = "dog cat cat dog"
> 输出: true

示例 2:

> 输入:pattern = "abba", str = "dog cat cat fish"
> 输出: false

示例 3:

> 输入: pattern = "aaaa", str = "dog cat cat dog"
> 输出: false

示例 4:

> 输入: pattern = "abba", str = "dog dog dog dog"
> 输出: false

说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    

## 解答

这题怎么那么像[同构字符串](https://github.com/joeyZhouYicheng/leetcode/blob/master/63%20-%20%E5%90%8C%E6%9E%84%E5%AD%97%E7%AC%A6%E4%B8%B2.md)

所以可以用两个哈希表存一下里面的值，每次遍历都找一下。

也可以把字符串变成数组，然后看对应的地方是不是一样的。这应该是最优解了

### indexOf

js的array，恰好也有indexOf这个函数，所以就直接抄代码了🙈

```js
var wordPattern = function (pattern, str) {
  const pattern_array = pattern.split('')
  const str_array = str.split(' ')
  if (pattern_array.length !== str_array.length) {
    return false
  }
  for (let i = 0; i < str_array.length; i++) {
    if (
      pattern_array.indexOf(pattern_array[i], i + 1)
      !== str_array.indexOf(str_array[i], i + 1)
    ) {
      return false
    }
  }
  return true
};
```

> Runtime: 52 ms, faster than 74.02% of JavaScript online submissions for Word Pattern.
>
> Memory Usage: 33.7 MB, less than 90.91% of JavaScript online submissions for Word Pattern.



go只能自己手写一个`findIndex`函数，也是蛮僵硬的。。

```go
func findIndex(slice []string, elem string, start int) int {
	for i := start; i < len(slice); i++ {
		if slice[i] == elem {
			return i
		}
	}
	return -1
}
func wordPattern(pattern string, str string) bool {
	pattern_slice := strings.Split(pattern, "")
	str_slice := strings.Split(str, " ")
	if len(pattern_slice) != len(str_slice) {
		return false
	}
	for i := 0; i < len(str_slice); i++ {
		if findIndex(pattern_slice, pattern_slice[i], i+1) != findIndex(str_slice, str_slice[i], i+1) {
			return false
		}
	}
	return true
}
```

> Runtime: 0 ms, faster than 100.00% of Go online submissions for Word Pattern.
>
> Memory Usage: 1.9 MB, less than 75.00% of Go online submissions for Word Pattern.