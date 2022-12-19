### 解题思路
按照习惯，我们分析一下算法是如何得到的。
（以下内容如果有不严谨的地方，欢迎指出并改正）

初看本题，第一疑问是这样的平衡字符串是不是一定可以分割成这样的n(>1)段，其中每一段都是平衡字符串。答案显然是否定的。那么第二个疑问就来了，取答案值的时候分割成n(>0))段，这n段一定都是平衡字符串吗？也不一定。比如样例中"LLLLRRRR"可以分割成"LLL", "LR", "RRR"三段，但答案依然是1。

这两个疑问解决后，我们再来看这个题。考虑任意一种分割，那么一定有 ``#(分割出的各段有非平衡的) ≤ #(分割出的各段全都平衡)`` （其中``#()``代表分割结果中平衡字符串的个数），由于本题只是求``#()``的最大值，因此不妨只考虑分割出的各段全都平衡的情况。

为了分割出最多的平衡字符串，我们应该从左往右进行一次遍历，每遇到一个极小的平衡字符串就计数一次。为了判断是否达到“平衡”，我们引入“平衡因子”a（类比``LeetCode1111``嵌套深度），深度增加时a++，深度下降时a--，当a为0时，说明又开始记录一个新的平衡字符串了。另外由于这题R和L都可以放在左侧，因此需要另外增加一个布尔变量add，记录此时是深度增加还是深度下降。（``1111``中的括号匹配，遇到``(``就是深度增加，遇到``)``就是深度下降，所以不用额外空间进行记录）


### 代码

```cpp
class Solution {
public:
	int balancedStringSplit(string s) {
		int cnt = 0;
		int a = 0;	// a: balanced factor
		bool add;
		for(int i = 0; i < s.length() - 1; i++) {
			if(!a) {		// if a == 0, start again (add is true for sure)
				if(s[i] == s[i + 1])	add = true;
				else add = false;
				a++;
				cnt++;
			}
			else {	// if a != 0
				if(add) {	// if is still increasing
					a++;
					if(s[i] == s[i + 1])	add = true;
					else	add = false;
				}
				else {
					a--;
					if(s[i] == s[i + 1])	add = false;
					else	add = true;
				}
			}
		}
		return cnt;
	}
};


```

![图片.png](https://pic.leetcode-cn.com/697b454a3cf92576ff6de1f03cc0b97fe5cef272354da2499040f8c37fd6bdf1-%E5%9B%BE%E7%89%87.png)
