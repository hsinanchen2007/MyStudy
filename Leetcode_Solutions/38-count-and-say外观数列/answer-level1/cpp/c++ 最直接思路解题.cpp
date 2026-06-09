### 解题思路
基本思路：设立一个指针从第一个字符开始遍历字符串，记录连续重复字符出现的个数再补上这个数字本身。
如：1->11 1个连续的1（11）  1211->111221 1个连续的1（11）+1个连续的2（12）+2个连续的1（21）
然后一直递推下去，直到n为止。
### 代码

```cpp
class Solution {
public:
	string countAndSay(int n) {
		string a = { '1' };//设立初始递推
		a.push_back(0);//在字符串末尾添加一个0，防止指针溢出
		string result; int tem = 1, flag = 1;
		string::iterator p = a.begin();
		while (flag < n)//在n之前不断递推
		{
			p = a.begin();
			while (p < a.end()-1)//因为在字符串末尾多添了一个元素所以可以比较到所有有效元素且防止了指针溢出
			{
				tem = 1;
				while (*p == *(p + 1))
				{
					tem++;
					p++;
				}
				result.push_back(char(tem) + 48);
				result.push_back(*p);
				p++;
			}
			a.resize(result.size());//在复制数组前确保有足够大的空间
			copy(result.begin(), result.end(),a.begin());
			a.push_back(0);//理由同上
			result.clear();
			flag++;
		}
		a.pop_back();//删除掉之前加的多余的0
		return a;

	}
};
```