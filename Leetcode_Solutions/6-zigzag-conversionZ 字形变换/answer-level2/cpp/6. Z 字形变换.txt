### 算法:

这个 `Z` 字型其实是这样的：

![image.png](https://pic.leetcode-cn.com/810b316c74a8eb0d2c97cbfc1bcf7559811f73b1bbed92848ba1bb7b9f1691b1-image.png)

对于前面的 `3` 行的 `示例1` , 它的字符数分布是这样的：


![image.png](https://pic.leetcode-cn.com/01f701396440902b127931f5a1a8a9ecbf70a9dc43ba2b7752a8756b8393e521-image.png)

对于前面的 `4` 行的 `示例2` , 它的字符数分布是这样的：

![image.png](https://pic.leetcode-cn.com/89ba53b0da11c91a66dbb05a75e4b9d83e853bbe3a82c7860cde1a6c1e0c9c8e-image.png)



那么对于 `n` 行的字符数分布是这样的：


![img](https://pic.leetcode-cn.com/d610b140dd0789204efe699672dc72a83e7b826da0165bbf083d24fc97ecdea7-image.png)



如上图所示，我们可以发现：

#### 1.当前行 `curRow` 为 `0` 或 `n-1` 时，箭头发生反向转折。

方法一： 从左到右按箭头方向迭代 `s` ，将每个字符添加到合适的行。之后从上到下遍历行即可。

我们假定 `n=numRows`  :

代码如下

``` c++ [-c++]
class Solution {
public:
	string convert(string s, int numRows) {

		if (numRows == 1) return s;

		vector<string> rows(min(numRows, int(s.size()))); // 防止s的长度小于行数
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) {// 当前行curRow为0或numRows -1时，箭头发生反向转折
				goingDown = !goingDown;
			}
			curRow += goingDown ? 1 : -1;
		}

		string ret;
		for (string row : rows) {// 从上到下遍历行
			ret += row;
		}

		return ret;
	}
};
```
比如对于 `s = "LEETCODEISHIRING"` ，得到的四行就是：

![image.png](https://pic.leetcode-cn.com/75fa4464b287f0d0ccb29218403257265beef3d50262a5f7cc872e7a93669cc7-image.png)

因为只需遍历一次，所以时间复杂度为 $`O(len(s))`$



#### 2.每一行字母的所有下标其实是有规则的

我们先假定有 `numRows=4` 行来推导下，其中 `2*numRows-2 = 6` , 我们可以假定为 `step=2*numRows-2` ，我们先来推导下规则：


第0行： `0` - `6` - `12` - `18`             

==> 下标间距 `6` - `6` - `6`  ==> 下标间距 `step`  - `step` - `step` 


第1行： `1 ` - `5` - `7` - `11 `- `13`   

==>   下标间距 `4` - `2` - `4` - `2  `==> 下标间距`step-2*1(行)`-`2*1(行)`-`step-2*1(行)`-`2*1(行)`

第2行： 2 - 4 - 8 - 10 - 14         
==>   下标间距 `2` - `4` - `2` - `4` ==> 下标间距`step-2*2(行)`-`2*2(行)`-`step-2*2(行)`-`2*2(行)`


第3行：3 - 9 - 15 - 21               

==>  下标间距间距 `6` - `6` - `6`  ==>下标间距`step`  - `step` - `step` 


__可以得出以下结论：__

0. 起始下标都是`行号`

1. 第`0`层和第`numRows-1`层的下标间距总是`step` 。

 2. 中间层的下标间距总是`step-2*行数`，`2*行数`交替。

 3. 下标不能超过`len(s)-1`

代码如下：
```c++ [-C++]
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		int step = numRows * 2 - 2; // 间距
		int index = 0;// 记录s的下标
		int len = s.length();
		int add = 0; // 真实的间距
		string ret;
		for (int i = 0; i < numRows; i++) // i表示行号
		{
			index = i;
			add = i * 2;
			while (index < len)//超出字符串长度计算下一层
			{
				ret += s[index]; // 当前行的第一个字母
				add = step - add;// 第一次间距是step -2*i，第二次是2*i, 
				index += (i == 0 || i == numRows-1) ? step : add; // 0行和最后一行使用step间距，其余使用add间距
			}
		}
		return ret;
	}
```



















