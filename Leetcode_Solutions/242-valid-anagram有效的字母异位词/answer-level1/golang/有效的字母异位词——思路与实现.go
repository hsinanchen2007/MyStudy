针对asii码字符用数组实现哈希表比较适合，如果是unicode则只能使用通用的哈希表。
至于排序再比较的方法，在go语言中是不太经济的，内存和时间开销都高。

关于编码相关的知识，参看阮一峰大神博客：
- <http://www.ruanyifeng.com/blog/2007/10/ascii_unicode_and_utf-8.html>

## 思路与实现

```go
package lt242

import (
	"fmt"
	"sort"
)

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//
//示例 1:
//
//    输入: s = "anagram", t = "nagaram"
//    输出: true
//示例 2:
//
//    输入: s = "rat", t = "car"
//    输出: false
//说明:
//你可以假设字符串只包含小写字母。
//
//进阶:
//如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

// 思考：
// 字母异位词就是说：两个单词所含字母及字母的数量都一样，但顺序不一样
// 那么显然最直接的想法就是在遍历word1时用一个数据结构记录出现过的字母的个数，再在遍历单次word2时（循环次数要设为word1长度）
// 去减去这个数据结构存储的相应字母的个数 ， 最后检查这个数据结构里所有字母的次数是否为0或者空。
// 这样的数据结构就是哈希表了，使用哈希表在遍历中实现O(1)的查找更新。其他可行方案比如链表查找效率低，会使得最终的时间复杂度达到O(N2)
// 所以方法1就是使用哈希表记录字母出现，遍历第二个单词时再递减删除哈希表记录的字母情况。时间O(n)，空间O(n)
// 		使用哈希表方法也可以优化一下，因为题目只有小写英文字母，所以可以用对应的asii码来表示各个字母，实现简单而不会碰撞的哈希表；
// 		如果考虑进阶情况（unicode字符，参考 https://zhihu.com/question/22881537 ），因为unicode规划有17个平面，每个平面分配65536个码点，
// 		如果这样也用码点映射到数组，占用太大，还是老老实实用内置通用的的哈希表
//
// 第二种方法是利用两个单词字母相同且字母出现次数也相同的特点，将其进行排序，排好序的单次必定相等。

// 1. 使用哈希表记录字母出现情况。暂时只考虑英文小写字母（97~122）
//34/34 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 75.19 % of golang submissions (3 MB)
func Sol_1_1(s string, t string) bool {
	// 这里我是把空字符串作为异常情况去return false; 两个字符串完全一致也return false
	//if len(s) == 0 || len(t) == 0 || len(s) != len(t) || s == t {
	//	return false
	//}

	// 经过测试，测试用例认为两个空字符串也算字母异位词，两个字符串完全一致也算字母异位词...醉
	if len(s) != len(t) {
		return false
	}

	// “哈希表”
	words := make([]int, 26)	// 0->97,...,25->122

	// 填充哈希表元素（字母出现的次数）
	for _, v := range s {
		words[int(v)-97]++
	}

	// 减去哈希表元素
	for _, v := range t {
		words[int(v)-97]--
	}

	// 判断哈希表是否全为0
	for _, v := range words {
		if v != 0 {
			return false
		}
	}

	return true
}

// 2. 使用哈希表记录字母出现情况。考虑unicode字符，用数组已经不合适，占内存太大，直接用通用哈希表
//34/34 cases passed (8 ms)
//Your runtime beats 68.7 % of golang submissions
//Your memory usage beats 75.19 % of golang submissions (3 MB)
func Sol_1_2(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	// 由于哈希表起始长度为0，所以需要截住 "" == "" 的特殊情况
	if len(s) == 0 {
		return true
	}

	// “哈希表”
	words := make(map[rune]int)	// rune在go中是int32别名，任何UTF-8编码（变长）的字符都可以直接用它表示（定长）

	fmt.Println("word s...")

	// 填充哈希表元素（字母出现的次数）
	for _, v := range s {
		words[v]++
		fmt.Printf("words[%v]=%d\n", v, words[v])
	}

	fmt.Println("word t...")

	// 减去哈希表元素，当为0时删除键
	for _, v := range t {
		words[v]--
		fmt.Printf("words[%v]=%d\n", v, words[v])
		if words[v] == 0 {
			delete(words, v)
		}
	}

	fmt.Printf("words=%v\n", words)

	// 判断哈希表是否为空	// 注意! map==nil和len(map)==0是两个概念！我们把所有键删除了，最后map就为空
	if len(words) == 0 {
		return true
	}

	return false
}

// 3. 还可以在1或2的基础上换一种写法
// 34/34 cases passed (8 ms)
//Your runtime beats 68.7 % of golang submissions
//Your memory usage beats 72.09 % of golang submissions (3 MB)
func Sol_1_3(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	// 由于哈希表起始长度为0，所以需要截住 "" == "" 的特殊情况
	if len(s) == 0 {
		return true
	}

	// “哈希表”
	words := make(map[rune]int)	// rune在go中是int32别名，任何UTF-8编码（变长）的字符都可以直接用它表示（定长）

	for i:=0; i<len(s); i++ {
		words[rune(s[i])]++
		words[rune(t[i])]--
	}

	// 检查哈希表的最终状态
	for _, v := range words {	// 不用检查key，只要发现有值非0，那么就false
		if v != 0 {
			return false
		}
	}

	return true
}

// 4. 直接字符串重排序再判等
// 时间O(logn)（快排），空间O(n)
//34/34 cases passed (16 ms)
//Your runtime beats 23.32 % of golang submissions
//Your memory usage beats 15.5 % of golang submissions (3.8 MB)
func Sol_1_4(s string, t string) bool {

	// 这里要提到一点，前面漏掉了一个重要的点：
	// go中 len(string)得到的是 byte数， 也就是字节数，但！ 不是字符数
	// 字母异位词的字符数一定相等，那么字节数也一定相等。但字节数相等不能得出字符数相等的结论！
	// 这里给纠正过来

	sRunes, tRunes := mySort(s), mySort(t)
	if len(sRunes) != len(tRunes) {
		return false
	}

	// 字符排序，注意是另申请了内存，所以空间消耗O(n)
	sort.Sort(sRunes)
	sort.Sort(tRunes)

	// 遍历字符数组，看有无不同
	for i:=0; i<len(sRunes); i++ {
		if sRunes[i] != tRunes[i] {
			return false
		}
	}

	return true
}

// 自定义sort.Interface的实现结构体
type mySort []rune

func (m mySort) Len() int {
	return len(m)
}

func (m mySort) Less(i, j int) bool {
	return m[i] < m[j]
}

func (m mySort) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

//var less = func(x, y rune) bool {
//	return x < y
//}


```