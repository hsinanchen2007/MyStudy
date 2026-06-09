// ## 题目

// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

// 示例 1:

// > 输入: s = "anagram", t = "nagaram"
// > 输出: true

// 示例 2:

// > 输入: s = "rat", t = "car"
// > 输出: false

// 说明:
// 你可以假设字符串只包含小写字母。

// 进阶:
// 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

// ## 解答


// 就是判断一下，字母是不是还是那些字母？

// 感觉可以一个个拿出来对比下，如果有，就删掉原来的字符串的字母

// ```js
var isAnagram = function (s, t) {
  if (s.length !== t.length) {
    return false
  }
  for (const item of t) {
    if (s.indexOf(item) !== -1) {
      s = s.replace(item, "")
    }
  }
  return s === ""
};
// ```

// > Runtime: 284 ms, faster than 5.04% of JavaScript online submissions for Valid Anagram.
// >
// > Memory Usage: 49.7 MB, less than 6.12% of JavaScript online submissions for Valid Anagram.

// replace后的结果需要再存到s里面，因为没做这个卡了半天😂😂

// 不过这个方法效率极慢

// ```go
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	for _, elem := range t {
		if strings.Contains(s, string(elem)) {
			s = strings.Replace(s, string(elem), "", 1)
		}
	}
	return s == ""
}
// ```

// > Runtime: 284 ms, faster than 5.04% of JavaScript online submissions for Valid Anagram.
// >
// > Memory Usage: 49.7 MB, less than 6.12% of JavaScript online submissions for Valid Anagram.

// go的话需要用`strings`的包，不过效率也太慢了吧。。怕是这种算法不够好

// ### 排序

// 排序并一一验证，感觉很酷😂咋就没想到呢。

// ```js
var isAnagram = function (s, t) {
  if (s.length !== t.length) {
    return false
  }
  s = s.split('').sort().join('')
  t = t.split('').sort().join('')
  return s === t
};
// ```

// > Runtime: 100 ms, faster than 36.20% of JavaScript online submissions for Valid Anagram.
// >
// > Memory Usage: 38.2 MB, less than 30.61% of JavaScript online submissions for Valid Anagram.

// 感觉稍微快了一点

// go就没这么方便了。。写得很僵硬

// ```go
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	sl := []byte(s)
	tl := []byte(t)
	sort.Slice(sl, func(i, j int) bool {
		return sl[i] < sl[j]
	})
	sort.Slice(tl, func(i, j int) bool {
		return tl[i] < tl[j]
	})
	for i, elem := range sl {
		if elem != tl[i] {
			return false
		}
	}
	return true
}
// ```

// > Runtime: 8 ms, faster than 56.80% of Go online submissions for Valid Anagram.
// >
// > Memory Usage: 3.2 MB, less than 16.67% of Go online submissions for Valid Anagram.

// 字符串怎么排序呢？不管怎么做都要变成切片，不然没法排序。

// 而go中字符串，是作为ascii码存的，也就是说看起来是字母，其实拿到手之后是数字

// 而字符串转切片，是不能`b := []string(s)`这样转的。不然：

// ```go
sl := []string{"a", "v", "b", "c",.....}
sort.Sort(sort.StringSlice(sl))
// ```

// 就直接排序完了



// 我查到，只能把字符串转成byte或uint8`	sl := []byte(s)`这样

// 排序这个，就只能手写一个`sort.Slice`函数，用第二个参数写一个函数来返回排序的方法

// 然后还需要最后循环对比一下数组



// 对比一下python，只需要一行😂😂

// ```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
// ```

// > Runtime: 60 ms, faster than 60.68% of Python3 online submissions for Valid Anagram.
// >
// > Memory Usage: 14.7 MB, less than 6.25% of Python3 online submissions for Valid Anagram.

// 虽然没go那么高效，但起码多保留了几根我的头发😂😂



// js也有一行解：

// > https://leetcode.com/problems/valid-anagram/discuss/310230/JS-1-line-solution

// ```js
var isAnagram = function(s, t) {
    return s.split('').sort().join('') == t.split('').sort().join('')
};
// ```

// > Runtime: 104 ms, faster than 30.24% of JavaScript online submissions for Valid Anagram.
// >
// > Memory Usage: 38.5 MB, less than 18.37% of JavaScript online submissions for Valid Anagram.

// js字符串转数组的一行解，还有[第二种方法](https://leetcode.com/problems/valid-anagram/discuss/128900/Yet-another-one-liner-JS-Solution.)：

// ```js
var isAnagram = function(s, t) {
    return [...t].sort().join('') === [...s].sort().join('');
};
// ```

// > Runtime: 112 ms, faster than 16.70% of JavaScript online submissions for Valid Anagram.
// >
// > Memory Usage: 42 MB, less than 6.12% of JavaScript online submissions for Valid Anagram.

// 就是似乎不怎么高效

// ### 哈希表

// 一开始的想法就是哈希表，但不知道怎么判断字母这个key，对应的value是否都为0，难不成要遍历一遍吗

// 题解：是的。

// 好吧。。

// ```go
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	count := make(map[uint8]int)
	for i := 0; i < len(s); i++ {
		count[s[i]]++
		count[t[i]]--
	}
	for _, elem := range count {
		if elem != 0 {
			return false
		}
	}
	return true
}
// ```

// > Runtime: 8 ms, faster than 56.80% of Go online submissions for Valid Anagram.
// >
// > Memory Usage: 3 MB, less than 83.33% of Go online submissions for Valid Anagram.

// 不知道为什么题解里面存的key，是`[s.charAt(i) - 'a']`，实测了一下，减不减a成本是一样的



// go里面有一点很僵硬，字符串里面存的是`rune`，即`int32`。而经过`for..range`之后，取出来的`elem`，却是一个`uint8`，也就是一个`byte`

// ```go
s := "abac"
for i, elem := range s {
  fmt.Println("elem", fmt.Sprintf("%T", elem))  // int32
  fmt.Println("i", fmt.Sprintf("%T", s[i]))    // uint8
}
// ```

// 所以要存map，只能统一用`i`来一起取，不然map的类型都就没法定义

// 感觉这个和取字符串的元素一样，很反直觉，为啥取出来的时候还要转换一下类型？也许和go的存储方式有关？



// > 作者：zit-3
// >
// > 链接：https://leetcode-cn.com/problems/valid-anagram/solution/js-jian-dan-xie-fa-by-zit-3/

// ```js
var isAnagram = function (s, t) {
  if (s.length !== t.length) {
    return false;
  }
  const obj = {};
  for (let i = 0; i < s.length; i++) {
    obj[s[i]] ? obj[s[i]]++ : (obj[s[i]] = 1)
    obj[t[i]] ? obj[t[i]]-- : (obj[t[i]] = -1)
  }
  return Object.keys(obj).every(item => obj[item] === 0);
};
// ```

// > Runtime: 68 ms, faster than 80.40% of JavaScript online submissions for Valid Anagram.
// >
// > Memory Usage: 36.2 MB, less than 59.18% of JavaScript online submissions for Valid Anagram.

// 不知道为啥题解中是用`charAt(i)`，实测和`s[i]`是一样的，而且用`s[i]`效率更高。。

// `charAt(i)`的意思是，`i`是一个index，返回这个index对应的元素。其实就和`s[i]`一样😂

// 也不知道js为啥要搞出这两个方法做同一件事。。

// ```js
...
  for (let i = 0; i < s.length; i++) {
    obj[s.charAt(i)] ? obj[s.charAt(i)]++ : (obj[s.charAt(i)] = 1);
    obj[t.charAt(i)] ? obj[t.charAt(i)]-- : (obj[t.charAt(i)] = -1);
  }
...
// ```

// > Runtime: 80 ms, faster than 50.43% of JavaScript online submissions for Valid Anagram.
// >
// > Memory Usage: 36.4 MB, less than 53.06% of JavaScript online submissions for Valid Anagram.

// `Array.every()`是用来[检验一个数组里面](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/every)，每个元素是否都满足某个条件。某个条件即括号里面的函数的返回值。都满足就最终返回true，不然返回false。

// 不过感觉这样不够高效，因为every可能和foreach或map一样，都一定要跑完全部元素。而我们只需要有一个false就可以退出了


// ```js
var isAnagram = function (s, t) {
...
  for (const i in obj) {
    if (obj[i] != 0) {
      return false
    }
  }
  return true
};

// ```

// > Runtime: 60 ms, faster than 95.80% of JavaScript online submissions for Valid Anagram.
// >
// > Memory Usage: 36.1 MB, less than 67.35% of JavaScript online submissions for Valid Anagram.


// 可以看到速度快了，占用内存也小了。



// 然后实测了一波，似乎every是有false就退出的😂

// ![image-20190906221207742](https://pic.leetcode-cn.com/355f8f623d89917de6434108edc815ab6df013492123959cd0e890c8b5f09554.jpg)

// 感觉js后面出来的骚操作，速度都没最简单的for循环要好，之前也遇到过哈哈😂




// 以前每次map都能略胜于obj，这次呢？

// ```js
var isAnagram = function (s, t) {
  if (s.length !== t.length) {
    return false
  }
  let count = new Map()
  for (let i = 0; i < s.length; i++) {
    count.get(s[i]) ? count.set(s[i], count.get(s[i]) + 1) : count.set(s[i], 1)
    count.get(t[i]) ? count.set(t[i], count.get(t[i]) - 1) : count.set(t[i], -1)
  }
  for (const item of count) {
    if (item[1] != 0) {
      return false
    }
  }
  return true
};
// ```

// > Runtime: 76 ms, faster than 56.94% of JavaScript online submissions for Valid Anagram.
// >
// > Memory Usage: 36.8 MB, less than 53.06% of JavaScript online submissions for Valid Anagram.

// 感觉不太行的亚子😂😂



// 关于`for..of`和`for..in`，感觉[这两者的区别](https://alligator.io/js/for-of-for-in-loops/)很有趣

// - in能取到数组的index，of能取到数组的内容

// - in能取到对象的key，但用of取不到value，反而会报错

// ![image-20190906221859606](https://pic.leetcode-cn.com/18029560224765c3b347a2ea2b741f17bcd70a253cb3cb72422cb8bdd05655b4.jpg)

// 换言之，数组底层也是类似于map的存咯，不过key就是其index？类似于。。

// ```js
const array = {
  0:"a",
  1:"b"
}
// ```

// 那为啥用of就取不到obj的value呢？是设计的时候就规定死了，obj不可迭代？

// - of能取到map的内容，但in取出来的是undefined

// ![image-20190906224441898](https://pic.leetcode-cn.com/9355cf8b4196b66a687c94988e45ad9c9073cfbd2d05f772fae56c7486801156.jpg)

// 所以map的存储类似于。。

// ```js
const map = [
  ["a", 1],
  ["b", 2]
]
// ```

// 如果换算成obj的话，map还是。。

// ```js
const map1 = {
  undefined: ["a", 1],
  undefined: ["b", 2]
}
// ```

// 这种感觉？？可迭代没key的obj？？



// ### 哈希表的第二种解法

// 先用s加，然后再用t减，如果有小于0的情况，就直接判false

// ```js
var isAnagram = function (s, t) {
  if (s.length !== t.length) {
    return false;
  }
  const obj = {};
  for (let i = 0; i < s.length; i++) {
    obj[s[i]] ? obj[s[i]]++ : (obj[s[i]] = 1)
  }
  for (let i = 0; i < t.length; i++) {
    if (!obj[t[i]]) {
      return false
    }
    obj[t[i]]--
    if (obj[t[i]] < 0) {
      return false;
    }
  }
  return true
};
// ```

// > Runtime: 68 ms, faster than 80.26% of JavaScript online submissions for Valid Anagram.
// >
// > Memory Usage: 36 MB, less than 77.55% of JavaScript online submissions for Valid Anagram.

// 如果t中有s没有的值，那么就直接变成false，或者如果有令其为0的值，也变成false

// 感觉每次都要判断两次，有点浪费，不过也想不到更好的方法了😂



// 用go写起来就简单一些，不用这么麻烦的判断了😂

// ```go
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	count := make(map[uint8]int)
	for i := 0; i < len(s); i++ {
		count[s[i]]++
	}
	for i := 0; i < len(t); i++ {
		count[t[i]]--
		if count[t[i]] < 0 {
			return false
		}
	}
	return true
}
// ```

// > Runtime: 8 ms, faster than 57.14% of Go online submissions for Valid Anagram.
// >
// > Memory Usage: 3 MB, less than 50.00% of Go online submissions for Valid Anagram.

// ### 使用数组

// 就是创建一个数组，一共26个格子，对应26个字母。如果s有就在那个位置+1，t就-1

// ```go
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	m := make([]int, 26)
	for i := 0; i < len(s); i++ {
		m[s[i]-'a']++
	}
	for i := 0; i < len(s); i++ {
		m[t[i]-'a']--
		if m[t[i]-'a'] < 0 {
			return false
		}
	}
	return true
}
// ```

// > Runtime: 0 ms, faster than 100.00% of Go online submissions for Valid Anagram.
// >
// > Memory Usage: 3 MB, less than 100.00% of Go online submissions for Valid Anagram.

// 哇塞。。速度超快！

// 那如果是用第一种做法呢？效果也一样吗？

// ```go
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	m := make([]int, 26)
	for i := 0; i < len(s); i++ {
		m[s[i]-'a']++
		m[t[i]-'a']--
	}
	for _, elem := range m {
		if elem != 0 {
			return false
		}
	}
	return true
}
// ```

// > Runtime: 0 ms, faster than 100.00% of Go online submissions for Valid Anagram.
// >
// > Memory Usage: 3 MB, less than 100.00% of Go online submissions for Valid Anagram.

// 好吧根本看不出差别。



// js好像没啥办法，能创建固定大小的数组。

// 但为了之后的++方便，需要[把26个位置都填为0](https://segmentfault.com/a/1190000003861423)

// 全填为0的方法，似乎是for循环最简单粗暴效率高了。

// ```js
var isAnagram = function (s, t) {
  if (s.length !== t.length) {
    return false;
  }
  var m = [];
  for (var n = 0; n < 26; n++) {
    m[n] = 0
  }
  for (let i = 0; i < s.length; i++) {
    m[s[i].charCodeAt() - 97]++
  }
  for (let i = 0; i < t.length; i++) {
    m[t[i].charCodeAt() - 97]--
    if (m[t[i].charCodeAt() - 97] < 0) {
      return false;
    }
  }
  return true
};
// ```

// > Runtime: 60 ms, faster than 95.74% of JavaScript online submissions for Valid Anagram.
// >
// > Memory Usage: 35.7 MB, less than 93.88% of JavaScript online submissions for Valid Anagram.

// 这个算法好像是速度最快的

// js换算对应的ascii码，还需要用`s[i].charCodeAt()`转一下，这么说来go的直接rune相见，在某些情况下还是挺实用的吼😂😂

