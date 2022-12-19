### 解题思路
利用unordered_map作滑动窗口
算法：
1.初始化头尾指针分别为head=0,tail=0
2.tail指针右移，并将tail所指元素加入到窗口中，判断tail当前指向的元素在滑动窗口中是否出现，
	- 如果出现，则将滑动窗口当前head所指元素数量-1，并移动head，直到该窗口中不包含该元素.
	- 如果未出现，则更新res，并进行下一轮循环，直到tail=s.size()

3.返回结果res
### 代码

```cpp
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> window;
		int res = 0;//存储答案
		int head = 0, tail = 0;//双指针
		for (;tail<s.size();tail++)
		{
			char temp = s[tail];//当前字符
			window[temp]++;
			//判断该窗口中是否存在该元素
			//如果存在该元素，使head右移，直到该窗口不包含该元素
			while (window[temp]>1)
			{
				
				char temp2 = s[head];
				window[temp2]--;//滑动窗口中该字符数量-1
				head++;//右移
			}
			res = max(res, tail - head+1);
		}
		return res;
	}
};
```