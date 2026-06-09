**思想**

最初的想法：  用map记录p中每个字母的出现次数，依次遍历s上每个允许的子串，判断每个字母的出现次数一不一样就可以了。
结果在最后一个测试用例超时。想了想，是因为每次判断的时候，对子串的操作有很多重复的比较。

于是基于原暴力法进行改良，去掉重复的比较：

 1. 遍历P中元素，每遍历一个元素，就将MAP中此元素的值+1。获得了p中的每个元素的个数。 
 2. 在S上从头截取与P相同长度的子串S1，遍历其中元素，每遍历一个元素，就将MAP中此元素的值 -1
 3. 判断MAP中所有的值是不是都为0，为0则符合了题意，输出此时S1子串的索引
 4. 将截取的子串S1往右移一位。
 5. **这时候你会发现：原子串中的第一个字符出去了，而最后一个字符进来了。我们把出去的字符在MAP中的值+1，进来的值-1。（避免了原暴力法中每次都要判断整个子串）**
 6. 重复345步骤，直到末尾。

**代码**
```

func findAnagrams(s string, p string) []int {
	pl := len(p)
	sl := len(s)
    if pl>sl{
        return nil
    }
	var result []int

	m := make(map[byte]int)
	for i := 0; i < pl; i++ {
		m[p[i]]++
	}

	for i1 := 0; i1 < pl; i1++ {
		m[s[i1]]--
	}

	for i := 0; i < sl-pl+1; i++ {

		flag := 0
        
		if i > 0 {
			m[s[i-1]]++
			m[s[i+pl-1]]--
		}
        
		for _, v := range m {
			if v != 0 {
				flag = 1
				break
			}
		}
		if flag == 0 {
			result = append(result, i)
		}

	}
	return result

}
```

