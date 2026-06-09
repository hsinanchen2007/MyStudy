# Go实现

## 第一思路

```go
package main

import "fmt"

func isAnagram(s string, t string) bool {
	// 1. 判断长度，异或必须为相等长度
	if len(s) != len(t) {
		return false
	}
	// 2. 定义map来标记每个字符出现的次数
	mark := map[rune]int{}
	// 3. 遍历s字符串，记录每个字符出现的次数
	for _, ss := range s {
		mark[ss] += 1
	}
	// 4. 判断每个字符出现的次数是否在另个字符串t中出现
	for _, tt := range t {
		_, ok := mark[tt]
		if !ok {
			// 如果没有出现匹配就返回失败
			return false
		} else {
			// 匹配就记录减一
			mark[tt] -= 1
		}
	}
	// 5. 遍历map看是否所有的字符都完成匹配并没有剩余的了
	for _, v := range mark {
		if v != 0 {
			return false
		}
	}
	return true
}
func main() {
	s := "aacc"
	t := "ccac"
	fmt.Println(isAnagram(s, t))
}
```
## map实现的优化

```go
package main

import (
	"fmt"
	"reflect"
)

func isAnagram(s string, t string) bool {
    m1 := make(map[rune]int)
    m2 := make(map[rune]int)

	for _, v := range s {
		m1[v] += 1
	}
	for _, v := range t {
		m2[v] += 1
	}

	return reflect.DeepEqual(m1, m2)
}
func main() {
	s := "aacc"
	t := "ccac"
	fmt.Println(isAnagram(s, t))
}

```

## 桶排序
使用两个数组，数组是值类型，相同类型，相同长度是一个类型，可以直接对比

```go
func isAnagram(s string, t string) bool {
	if !(len(s) == len(t)) {
		return false
	}
	var (
		bucket1 [26]int
		bucket2 [26]int
	)
	for _, v := range s {
		bucket1[v-'a']++
	}
	for _, v := range t {
		bucket2[v-'a']++
	}
	return bucket1 == bucket2
}
```

## 思路

1. 按字典序排序，查看是否相等 快排O(nlogn)
1. Map计数个数O(N)


# Python实现

```python
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return sorted(s) == sorted(t)
```

## 经典做法

```python
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dic1, dic2 = {}, {}
        for item in s:
            dic1[item] = dic1.get(item, 0) + 1
        for item in t:
            dic2[item] = dic2.get(item, 0) + 1
        return dic1 == dic2
```

```python
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dic1, dic2 = [0]*26, [0]*26
        for item in s:
            dic1[ord(item)-ord('a')] += 1
        for item in t:
            dic2[ord(item)-ord('a')] += 1
        return dic1 == dic2
```