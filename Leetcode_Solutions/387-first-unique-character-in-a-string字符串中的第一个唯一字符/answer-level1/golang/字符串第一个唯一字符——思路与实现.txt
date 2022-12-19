
采用了与官方解法思路不太一样的做法，性能表现稍好，但代码较为复杂，有兴趣可以看看。

## 思路与实现

```go
package lt387

// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
//
//案例:
//
//s = "leetcode"
//返回 0.
//
//s = "loveleetcode",
//返回 2.
// 
//
//注意事项：您可以假定该字符串只包含小写字母。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 思考：
// “第一个” 要求记录下标信息
// "不重复" 要求有机制将重复的和不重复的分开

// 1. 哈希表记录字符第一次出现的下标，如重复则置-1，最后哈希表中值大于-1的全是不重复的，取最小值即可
// 2. 因为只有英文小写字母，用数组来模拟哈希表


// 1. 哈希表
// O(n)/O(n)
//func firstUniqChar(s string) int {
//	m := make(map[byte]int)		// 只有英文小写字母，所以直接用byte作键
//	// 要注意使用for range遍历string时，其value是 rune(也就是int32)，所以这里用下标遍历
//	for i:=0; i<len(s); i++ {		// len(s)取的是字节数
//		v := m[s[i]]
//
//		if v != 0 {		// != 0 说明出现过； != -1说明最多只出现了一次
//			if v == -1 {
//				continue	// 继续下一次for
//			}
//			// 否则说明此前只出现一次，这时要将它置-1
//			m[s[i]] = -1
//		}
//
//		// 这里则是 v==0，就需要记录其下标了
//		m[s[i]] = i
//	}
//
//	// 上面要注意一个特殊情况，就是第一个字符，其下标为0
//	// 首先其第一次出现时，i=0, m[s[i]]==0 所以会置m[s[i]] = 0
//	// 如果第二次出现，会发现 m[s[i]]==0, 然后会将 m[s[i]]置一个正整数
//	// 所以必须避免这个情况，将考虑了这个问题的解答重新记录写下
//
//
//	// 遍历m找最小的非负数
//	// TODO
//
//	return 0
//}
// 104/104 cases passed (36 ms)
//Your runtime beats 65.44 % of golang submissions
//Your memory usage beats 91.81 % of golang submissions (5.7 MB)
func firstUniqChar1(s string) int {
	m := make(map[byte]int)		// 只有英文小写字母，所以直接用byte作键

	// 为了避免下标0的尴尬，哈希表的值记录的是下标+1
	var v int
	for i:=0; i<len(s); i++ {		// len(s)取的是字节数
		v = m[s[i]]

		if v != 0 {		// != 0 说明出现过； != -1说明最多只出现了一次
			if v == -1 {
				continue	// 继续下一次for
			}
			// 否则说明此前只出现一次，这时要将它置-1
			m[s[i]] = -1
			continue
		}

		// 这里则是 v==0，就需要记录 其下标+1 了
		m[s[i]] = i+1
	}

	// 遍历m找最小的非负数
	target := len(s)	// 初始为最大的下标+1，慢慢比较，找到最小值
	uniqNum := len(m)	// uniqNum记录的是所有不重复的字符个数，一开始不知道，设为哈希表长度
	for _, v := range m {
		if v > 0 {
			if v < target {
				target = v
			}
		} else {
			uniqNum--
		}
	}
	// 在哈希表里有不重复字符时会得到其位置，那如果是没有不重复字符呢？所以需要加一个变量记录是否有不重复字符

	if uniqNum == 0 {return -1}
	return target-1
}

// 1. 数组作哈希表
// O(n)/O(n)
// 104/104 cases passed (4 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 81.29 % of golang submissions (5.8 MB)
func firstUniqChar2(s string) int {
	m := make([]int, 26)

	// 为了避免字符串第一个字符下标0的尴尬，哈希表的值记录的是下标+1
	var index uint8
	var value int
	for i:=0; i<len(s); i++ {		// len(s)取的是字节数
		index = s[i] - 97
		value = m[index]

		if value != 0 {		// != 0 说明出现过； != -1说明最多只出现了一次
			if value == -1 {
				continue	// 继续下一次for
			}
			// 否则说明此前只出现一次，这时要将它置-1
			m[index] = -1
			continue
		}

		// 这里则是 v==0，就需要记录 其下标+1 了
		m[index] = i+1
	}

	// 遍历m找最小的非负数
	target := len(s)	// 初始为最大的下标+1，慢慢比较，找到最小值
	uniqNum := len(m)	// uniqNum记录的是所有不重复的字符个数，一开始不知道，设为哈希表长度
						// 这里尽管数组存的话可能有没有的字符，其在m中值为0，但在下面的代码中仍然被处理掉了，所以没有问题
	for _, v := range m {
		if v > 0 {
			if v < target {
				target = v
			}
		} else {
			uniqNum--
		}
	}
	// 在哈希表里有不重复字符时会得到其位置，那如果是没有不重复字符呢？所以需要加一个变量记录是否有不重复字符

	if uniqNum == 0 {return -1}
	return target-1
}


// 总结一下，我的两种解法都是 先遍历一遍字符串得到哈希表，再遍历一遍哈希表找到目标。

// 而官方题解等大多数解法都是采用 先遍历一遍字符串得到哈希表，再遍历一遍字符串去哈希表判断是否不重复，从而得到目标。

// 这里按照官方题解思路再实现一次
// 104/104 cases passed (4 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 83.04 % of golang submissions (5.8 MB)
func firstUniqChar3(s string) int {
	m := make([]int, 26)		// 值存出现次数

	for i:=0; i<len(s); i++ {
		m[s[i]-97]++
	}

	// 再遍历一遍字符串，找目标字符下标
	for i:=0; i<len(s); i++ {
		if m[s[i]-97] == 1 {
			return i
		}
	}

	return -1
}
```