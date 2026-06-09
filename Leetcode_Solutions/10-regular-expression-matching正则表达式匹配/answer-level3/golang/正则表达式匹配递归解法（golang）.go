提供一种使用递归的方法，特别省空间，因为仅仅是游标循环，计算过程中几乎不需要缓存
但是因为递归本质上是一种尝试循环并返回其中正确的匹配结果，所以从时间复杂度上相对较高

有个点比较特殊就是*号匹配，由于有三种选择
- **字符串游标（si）继续前进（si+1）**
- **匹配游标（pi）继续前进（pi+2）**
- **两者都前进（si+1，pi+2）**
无论哪种都是可以让匹配递归继续进行下去的
只是从这些递归返回的结果看，有的可能成功，有的可能失败
但是这三种只需要有一种可以成功（说明可以探底到唯一的true），那么就可以向上返回成功

返回false的情况有这么几种：
- 目标字符串在非*匹配的情况下到达到了末尾（si）
- 目标字符串中的某个字符在严格匹配中失败

完美返回true的只有一种情况，就是si和pi同时到达了末尾
这里值得注意的是si在递归过程中可能并不会增加，而是等待pi到达末尾，这种情况则是p序列最后有N个连续的*匹配

代码如下：

```
func isMatch(s string, p string) bool {
	pLen := len(p)
	sLen := len(s)
	if pLen == 0 && sLen == 0 {
		return true
	}
	if pLen == 0 {
		return false
	}
	if p == ".*" {
		return true
	}
	return matchSwitchState(0, 0, s, p)
}

func matchSwitchState(si int, pi int, s string, p string) bool {
	pLen := len(p)
	sLen := len(s)
	//同时到达尾端 唯一可能返回true的情况
	if pi >= pLen && si >= sLen {
		return true
	}
	//匹配器没有了 但是字符还有
	if pi >= pLen && si < sLen {
		return false
	}
	//分情况向下递归 分别是 星号匹配 / 点号匹配 / 精确字符匹配
	if pi+1 < len(p) && p[pi+1] == byte('*') {
		mateByte := p[pi]
		//匹配超出 但星号匹配是可以忽略并继续步进到下一个匹配器的
		if si >= sLen {
			return matchSwitchState(si, pi+2, s, p)
		}
		//匹配到了有三种种选择 注意，匹配有两种情况 比较特殊的一种是'.*'可以和任意字符匹配
		//三种步进方式都有可能
		if s[si] == mateByte || mateByte == byte('.') {
			return matchSwitchState(si, pi+2, s, p) || matchSwitchState(si+1, pi, s, p) || matchSwitchState(si+1, pi+2, s, p)
		}
		//没有匹配到则只能匹配器继续步进下去，注意，*匹配器步进要向后两步
		return matchSwitchState(si, pi+2, s, p)
	} else if p[pi] == byte('.') {
		//匹配超出
		if si >= sLen {
			return false
		}
		//点号 可匹配任何字符 直接继续双步进即可
		return matchSwitchState(si+1, pi+1, s, p)
	} else {
		//匹配超出
		if si >= sLen {
			return false
		}
		//具体字符 只能严格匹配
		if p[pi] != s[si] {
			return false
		}
		return matchSwitchState(si+1, pi+1, s, p)
	}
}
```
