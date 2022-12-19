
### 思路
1. 因为 ip 固定是 4 个数字，每个数字的长度范围是 1-3 。
   11. 取第 n 个数字的时候，可以通过计算，得到后续数字所需的必要字符串长度，缩小判断范围。
   12. 处理最后一个数字时，要直接取到字符串最后一位。
2. ip中每个数字的范围是 0-255 ，可以根据这个特点缩小判断范围。
   21. 注意使用 `stoi` 转换时 “01” 也是可以转换成 1 的，可以考虑再转回来与字符串对比排除。
3. 取得一个的合法数字后，递归调用取下一个。
   31. 直到得到最后一个合法数字，这个 ip 便是合法的。返回这个合法的 ip 。
   32. 如果不合法，立即返回到前一位。
4. 当一个数字（合法或不合法）处理完毕，循环会进入下一个范围内的数字，进行判断。


### 答题
```C++
vector<string> restoreIpAddresses(string& s, int remaining, int iBegin)
{
	int len = s.length();
	vector<string> ret;
	for (int i = iBegin; i < iBegin + 3; i++)
	{
		// remaining 表示剩余几位
		if (remaining == 0 && i != len - 1) continue;	// 如果是最后一位，必须匹配到字符串结尾
		if ((len - i - 1) > (remaining * 3)) continue;	// 根据是第几位，确定在字符串中的可能位置
		if ((len - i - 1) < (remaining * 1)) continue;

		string sub = s.substr(iBegin, i - iBegin + 1);
		int ip = stoi(sub);
		if (ip < 0 || ip > 255) continue;	// 不符合 ip 格式
		if (to_string(ip) != sub) break;	// 处理 stoi(“01”) => 1 的特殊情况

		if (remaining == 0)
		{
			// 最后一位得到合法数字，返回答案
			ret.push_back(sub);
		}
		else
		{
			// 按照当前状态，进一步寻找下一位数字
			vector<string> vs = restoreIpAddresses(s, remaining - 1, i + 1);
			for (auto& v : vs)
			{
				// 只有后续数字合法，vs 不为空，此处的 sub 才能加入答案
				// 因此过滤了不符合的答案
				ret.push_back(sub + "." + v);
			}
		}
	}
	return ret;
}

vector<string> restoreIpAddresses(string s)
{
	return restoreIpAddresses(s, 3, 0);
}
```

### 测试用例
```
输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
```

```
输入: "010010"
输出: ["0.10.0.10","0.100.1.0"]
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)