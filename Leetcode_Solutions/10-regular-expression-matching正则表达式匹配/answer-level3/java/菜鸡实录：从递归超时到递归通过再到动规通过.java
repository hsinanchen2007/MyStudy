- 一开始看到这题的心态是放弃的，感觉情况非常复杂！后来偶然看到一篇稍微比较好理解的题解，看了一半有点理解怎么做，可是剩下一半实在是看不下去了，觉得自己应该可以写出来，于是今天下午就倔强地把这道题一步步写出来。
--- 
- 前言：说实话递归写法真的不难，虽然不建议传统暴力，但是做动规前有必要先实现一下暴力递归算法，其它题目基本也是这样。一步步自己优化，那样做题才有成就感，建议优化时实在想不出可以看看别人是怎么做的，看完自己敲，按自己的理解实现代码！！！
---
- 其实这题的关键点在于p字符串中有`*`，其能匹配前面一个字符的0个或任意个。
- 若没有`*`，直接一一比较即可！
- 若有`*`字符，需要考虑的情况有点多，说实话，别被吓住了，没有你想象这么南，自己举一下简单的几个栗子情况不就出来了么？递归终止条件好写，也就是两个字符串都为空，于是当时我就用了两个判断：提交的时候活生生地被一样样例卡住了：`a`、`ab*`，想了想就去掉了下面一行代码，至于为什么，大家带着思考debug！
```java
if (p.isEmpty()) return s.isEmpty();
if(s.isEmpty()) return p.isEmpty(); // 去掉此行代码重新思考
```
- 下面就直接重头戏把，从WA到AC需要自己去体会，在这我就不bb了，懒~
- 解题关键点，讨论字符`*`的匹配次数：
1. 若`s[i]==p[j]`，需要判断`p[j+1]=='*'`（注意边界），若是，则接下来分3种情况递归，否则继续递归`isMatch(s[1:],p[1:])`。
> ①`*`为0次匹配，如abb、`a*abb` --> isMatch(s, p[2:]) --> isMatch(abb, abb)
②`*`为1次匹配，如abb、`a*bb` --> isMatch(s[1:], p[2:]) --> isMatch(bb, bb)
③`*`为多次匹配，如aaab、`a*b` --> isMatch(s[1:], p); --> isMatch(abb, `a*b`)

2. 若`p[j]=='.'`，需要判断`p[j+1]=='*'`（注意边界），若是，则接下来分3种情况递归，否则继续递归`isMatch(s[1:],p[1:])`。
> ①若`*`为0次匹配，如：abb、`.*abb` --> isMatch(s, p[2:])
②若`*`为1次匹配，如：abb、`.*bb` --> isMatch(s[1:], p[2:])
③若`*`为多次匹配，如：aaab、`.*` --> isMatch(s[1:], p)

可以发现以上两种情况可以合并判断，也就是当`s[i]==p[j] || p[j]=='.'`时，有上面的递归。

3. 若`s[i] != p[j]`，需要先看p字符串的下一个字符是否为`*`，若是则直接取`*`匹配0次，即`isMatch(s, p[2:])`，否则`return false`。
4. 还有一种情况，若s字符串为空，但是p可能不为空，如：p剩下`b*`等，如：输入为`a`、`ab*`，接下来单独判断字符串p，若其下一个字符是`*`，则继续递归`isMatch(s, p[2:])`，否则`return false`。
5. 通过层层冒险，递归终止条件为：只有当字符串遍历完，若s为空，则说明已经匹配完成，否则匹配失败！即`if (p.isEmpty()) return s.isEmpty();`
---
- 刚开始根据自己的思路，用递归写，一路“开挂”，一直WA，根据提交返回的错误运行样例，然后用自己的理解分情况讨论，直到提交超时后，我重新梳理了各个情况，发现有个情况可以合并，下面先给出超时代码：（一般情况下，做题的时候为了避免健忘症，建议分情况讨论时给代码加上注解，这样有助于整体理解和帮助记忆）
```java
class Solution {
	public boolean isMatch(String s, String p) {
		// 终止条件：若模式串为空，并且s字符必须为空才匹配
		if (p.isEmpty())
			return s.isEmpty();
		if (s.isEmpty()) {
			// 如果s字符串为空，但是p可能不为空，如：p剩下b*等
			// 若p的长度不小于2，并且p[1]=='*'，则直接舍弃当前部分 isMatch(s, p[2:])
			if (p.length() > 1 && p.charAt(1) == '*')
				return isMatch(s, p.substring(2));
			// 若p的长度为1，或者p的下一个字符不是*，显然是不匹配的
			return false;
		}
		// 判断当前位置的字符，i，j，前提是s字符串不为空
		else if (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.') { // 如果对应位置的字符相同，那就判断下一个字符是否为*
			// 若p模式串还有下一个字符，且为*
			// 分3种情况：
			// ①*为0次匹配，如abb、a*abb --> isMatch(s, p[2:])
			// ②*为1次匹配，如abb、a*bb --> isMatch(s[1:], p[2:])
			// ③*为多次匹配，如aaab、a*b --> isMatch(s[1:], p);

			// 若当前p[0]为.，则判断下一个字符是否为*
			// 若为*，也分3种情况，讨论*取的个数
			// ① 若*为0次匹配，如：abb、.*abb --> isMatch(s, p[2:])
			// ② 若*为1次匹配，如：abb、.*bb --> isMatch(s[1:], p[2:])
			// ③ 若*为多次匹配，如：aaab、.* --> isMatch(s[1:], p)
			if (p.length() > 1 && p.charAt(1) == '*') {
				return isMatch(s, p.substring(2)) || isMatch(s.substring(1), p.substring(2))
						|| isMatch(s.substring(1), p);
			}
			// 若p剩下长度为1，或者p的下一个字符不是*，则直接递归下一次比较
			// 若p剩下长度为1，或者p的下一个字符不是*，则直接递归下一次比较，因为 '.'只匹配单个字符
			return isMatch(s.substring(1), p.substring(1));
		} else {
			// 其余情况不相等，先看下一个字符是否为*，若是则直接取*匹配0个 --> isMatch(s, p[2:])
			if (p.length() > 1 && p.charAt(1) == '*')
				return isMatch(s, p.substring(2));
			// 若p剩下长度为1，或者p的下一个字符不是*，则直接返回false
			return false;
		}
	}
}
```
- 相信聪明的人都看出哪里出错了，没错，若下一个字符为`*`且匹配一次这种情况，超时代码递归了2次，导致运行这个样例的时候超时~~~
```
"aaaaaaaaaaaaab"
"a*a*a*a*a*a*a*a*a*a*c"
```

![超时截图.png](https://pic.leetcode-cn.com/16c2efa7aaf917cccde1135ce70dbc03ff298d27ac7a05c65264980af089a015-WeChat%20Screenshot_20200303162903.png)

- 于是把情况简单地进行合并，把下一个字符是`*`且匹配1次的情况合并到下面，也就有了下面这样的代码（注释掉了一种情况）：运行时间大大减少！
```java
class Solution {
	public boolean isMatch(String s, String p) {
		// 终止条件：若模式串为空，并且s字符必须为空才匹配
		if (p.isEmpty())
			return s.isEmpty();
		if (s.isEmpty()) {
			// 如果s字符串为空，但是p可能不为空，如：p剩下b*等
			// 若p的长度不小于2，并且p[1]=='*'，则直接舍弃当前部分 isMatch(s, p[2:])
			if (p.length() > 1 && p.charAt(1) == '*')
				return isMatch(s, p.substring(2));
			// 若p的长度为1，或者p的下一个字符不是*，显然是不匹配的
			return false;
		}
		// 判断当前位置的字符，i，j，前提是s字符串不为空
		else if (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.') { // 如果对应位置的字符相同，那就判断下一个字符是否为*
			// 若p模式串还有下一个字符，且为*
			// 分3种情况：
			// ①*为0次匹配，如abb、a*abb --> isMatch(s, p[2:])
			// ②*为1次匹配，如abb、a*bb --> isMatch(s[1:], p[2:])
			// ③*为多次匹配，如aaab、a*b --> isMatch(s[1:], p);

			// 若当前p[0]为.，则判断下一个字符是否为*
			// 若为*，也分3种情况，讨论*取的个数
			// ① 若*为0次匹配，如：abb、.*abb --> isMatch(s, p[2:])
			// ② 若*为1次匹配，如：abb、.*bb --> isMatch(s[1:], p[2:])
			// ③ 若*为多次匹配，如：aaab、.* --> isMatch(s[1:], p)
			if (p.length() > 1 && p.charAt(1) == '*') {
				return isMatch(s, p.substring(2)) /* 把这种情况放合并到下面 || isMatch(s.substring(1), p.substring(2)) */
						|| isMatch(s.substring(1), p);
			}
			// 若p剩下长度为1，或者p的下一个字符不是*，则直接递归下一次比较
			// 若p剩下长度为1，或者p的下一个字符不是*，则直接递归下一次比较，因为 '.'只匹配单个字符
			return isMatch(s.substring(1), p.substring(1)); // 合并上面那种情况
		} else {
			// 其余情况不相等，先看下一个字符是否为*，若是则直接取*匹配0个 --> isMatch(s, p[2:])
			if (p.length() > 1 && p.charAt(1) == '*')
				return isMatch(s, p.substring(2));
			// 若p剩下长度为1，或者p的下一个字符不是*，则直接返回false
			return false;
		}
	}
}
```
- 结果提交上去，81ms，AC
![AC.png](https://pic.leetcode-cn.com/39dcaa13926f18734940fd18141777e866aec585f95526c6e52a4ab0e75b8a7d-WeChat%20Screenshot_20200303163045.png)

![All WA, Once AC.png](https://pic.leetcode-cn.com/0608c5158e03cffbc7002c9679ec6ee27c733f8c251d1f86fd78f16a64a1694c-WeChat%20Screenshot_20200303170833.png)

- 至于时间复杂度就不用说了，肯定很大，比较复杂，这时记忆化就得用上了。直接上代码！
```java
class Solution {
	private Boolean[][] vis;// 定义为boolean类型的封装类
	private int len1, len2;

	public boolean isMatch(String s, String p) {
		len1 = s.length();
		len2 = p.length();
		vis = new Boolean[len1 + 1][len2 + 1];
		return dfs(s, 0, p, 0);
	}

	private boolean dfs(String s, int cur1, String p, int cur2) {
		if (cur1 > len1 || cur2 > len2)
			return false;
		if (cur2 == len2) // 只有当p遍历完，再来判断s是否也刚好遍历完
			return cur1 == len1;
		// 还有一种情况：若s为空，p不为空，p可能匹配为空
		if (vis[cur1][cur2] != null)
			return vis[cur1][cur2];
		if (cur1 == len1 || (s.charAt(cur1) != p.charAt(cur2) && p.charAt(cur2) != '.')) {
			// s为空，p可能0匹配最后被消掉
			// 2个字符不相等，需要判断p的第二个字符是否为*，若是则这个p[j]可舍弃
			if (cur2 + 1 < len2 && p.charAt(cur2 + 1) == '*')
				return vis[cur1][cur2] = dfs(s, cur1, p, cur2 + 2);
			// 否则直接返回false
			return vis[cur1][cur2] = false;
		} else { // s.charAt(cur1) == p.charAt(cur2) || p.charAt(cur1) == '.'
			if (cur2 + 1 < len2 && p.charAt(cur2 + 1) == '*')
				// 匹配的情况处理都相同
				// 0个匹配：abb和a*abb
				// 1个匹配：abb和a*bb，此种情况可以合并到下面一个return情况
				// 多个匹配：aaab和a*b
				return vis[cur1][cur2] = dfs(s, cur1, p, cur2 + 2) || dfs(s, cur1 + 1, p, cur2);
			// p的第二个字符不是*，则直接进入下一轮进行比较
			return vis[cur1][cur2] = dfs(s, cur1 + 1, p, cur2 + 1);
		}
	}
}
```

![okAC,nice](https://pic.leetcode-cn.com/66c0f5c70afa310e37474f2d72a89622d8b5ba55d2bceb378a52464f340837a3-WeChat%20Screenshot_20200311170926.png)

- 动规写法：定义dp[i][j]为s的前i个字符是否都能被p字符串中的前j个字符匹配，根据递归的特性，都是从子问题得来，于是我们先去算子问题，也就是从后往前推，注意边界，稍微改一下代码即即可！
```java
class Solution {
	public boolean isMatch(String s, String p) {
		int m, n;
		if (s == null && p == null)
			return true;
		else if (s == null || p == null)
			return false;
		m = s.length();
		n = p.length();
		boolean[][] dp = new boolean[m + 1][n + 1]; // ！
		for (int i = m; i >= 0; i--) {
			for (int j = n; j >= 0; j--) {
				if (i == m && j == n) // 表示都是空字符串
					dp[i][j] = true;
				else if (i == m) // s为空串
					dp[i][j] = (j + 1 < n && p.charAt(j + 1) == '*') ? dp[i][j + 2] : false;
				else if (j < n) {
					if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') {
						if (j + 1 < n && p.charAt(j + 1) == '*')
							dp[i][j] = dp[i][j + 2] | dp[i + 1][j];
						dp[i][j] |= dp[i + 1][j + 1];
					} else
						dp[i][j] = (j + 1 < n && p.charAt(j + 1) == '*') ? dp[i][j + 2] : false;
				}
			}
		}
		return dp[0][0];
	}
}
```
- 提交一发AC，当然这里可以改成压缩dp，有兴趣可以自己试试！完结撒花！

![AC_ONE.png](https://pic.leetcode-cn.com/8f29eb3c1e9550cfe07debf3f3053abf1db4d8ba627c4af5ec6791eb70e2eccf-WeChat%20Screenshot_20200303180456.png)
