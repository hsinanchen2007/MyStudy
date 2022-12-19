### 解题思路
实在没看懂Manacher算法，自己想了一套，结果写出来发现跟Mancher算法基本一致，真是造化弄人。。。
- 对字符串进行插值，变成#a#b#c#c#的形式，记得边缘一定都要为#，这边#实际使用的是'\0'
- 记插值后的字符串为：a[0]...a[e']...a[i']...a[mid]...a[i]...a[e]...a[n]
- 记mid为当前扫描到回文串最右边界的中心，即其右边界目前最右
- 记e和e'为mid回文串的对称边界
- 令p[k]为以第k个字符为中心的最长回文串半径，则以点k为中心的最长回文子串坐标为[k-p[k],k+p[k]]
- 利用回文串的对称性加速搜索，其实就是利用了以下特性：
1. 对于mid右侧任一点i'
    - 若其对称点i的回文串半径p[i]在mid的回文串半径内，根据对称性，p[i']=p[i]；因为p[i]和p[i']是对称子串
    - 否则，从mid的回文串半径内外开始扫描，省去扫描已经扫描过的字段
2. 如果当前最右边界已经到达字符串末尾，则后面的节点都无需扫描，因为不可能再超过的边界了
3. 如果搜索确定某一回文字符串时，到达字符串末尾，则后面的节点都无需扫描，因为不可能再超过的边界了

### 代码
```golang
// 马拉车算法
// 最广回文法
// a[0]...a[e]...a[j]...a[mid]...a[i]...a[e']...a[n]
// 记mid为当前最新扫描到的最长回文串中心
// e和e'为对应回文串的对称边界
// 令p[k]为以第k个字符为中心的最长回文串半径
func longestPalindrome(s string) string {
	if len(s) <= 1 {
		return s
	}
	l := len(s)
	ss := make([]byte, l+l+1)
	ss[0] = 0
	ss[len(ss)-1] = 0
	for idx := 0; idx < len(s); idx++ {
		ss[idx*2+1] = s[idx]
	}
	sub := oddLongestPalindrome(string(ss))
	var res []byte
	// remove '\0'
	for _, c := range []byte(sub) {
		if c == 0 {
			continue
		}
		res = append(res, c)
	}
	return string(res)
}

// 马拉车算法
// 最广回文法
// a[0]...a[e]...a[i]...a[mid]...a[i']...a[e']...a[n]
// 记mid为当前最新扫描到的最长回文串中心，其右边界目前最右
// e和e'为对应回文串的对称边界
// 令p[k]为以第k个字符为中心的最长回文串半径，则以点k为中心的最长回文子串坐标为[k-p[k],k+p[k]]
// 对于mid右侧任一点i'，若其对称点i的回文串半径p[i]在mid的回文串半径内，根据对称性，p[i']=p[i]；因为p[i]和p[i']是对称子串
// 否则，从mid的回文串半径内外开始扫描，省去扫描已经扫描过的字段
func oddLongestPalindrome(s string) string {
	if len(s) <= 1 {
		return s
	}
	p := make([]int, len(s))
	var mid int // 当前边界最右的中心节点
	var max int // 当前回文半径最大的中心节点
	// i≥mid, always
	for i := 1; i < len(s); i++ {
		var startPos int
		// 当前节点位于mid的回文半径内
		if i <= mid+p[mid] {
			//获得点i的对称点i'
			mirrorI := 2*mid - i

			//获得mid的左边界点e'
			mirrorE := mid - p[mid]
			//获得点i'的左边界点ie
			mirrorIE := mirrorI - p[mirrorI]
			//检测i'的回文串边界是否超过e'
			if mirrorE < mirrorIE { //根据对称性，p[i']=p[i]
				p[i] = p[mirrorE]
				continue
			}
			//从mid的右边界开始扫描，从而获取点i的右边界
			startPos = mid + p[mid] + 1
		} else {
			//从mid的右边界开始扫描，从而获取点i的右边界
			startPos = i + 1
		}
		j := startPos
		for ; j < len(s) && 2*i-j >= 0; j++ {
			if s[j] != s[2*i-j] {
				break
			}
		}
		p[i] = j - 1 - i
		if j == len(s) {
			//数组边界退回，也就是说，i的右边界为字符串结尾
			p[i] = len(s) - 1 - i
		}
		// 更新已知最右边界
		if i+p[i] > mid+p[mid] {
			mid = i
		}
		//获得trim 0 之后真实字符直径，p[i]是包含了0的半径
		score := func(i int) int {
			if s[i] == 0 { // 0c0c0
				return p[i]
			}
			// 0c0
			return 1 + (p[i] - 1)
		}
		// 更新最长回文串中心节点
		if score(i) > score(max) {
			max = i

			if max+p[max] >= len(s) {
				// 很明显，i后面的节点都无需扫描，不可能再超过i的边界了
				break
			}
		}
		if j == len(s) {
			// 很明显，i后面的节点都无需扫描，不可能再超过i的边界了
			break
		}
	}
	return s[max-p[max] : max+p[max]+1]
}
```