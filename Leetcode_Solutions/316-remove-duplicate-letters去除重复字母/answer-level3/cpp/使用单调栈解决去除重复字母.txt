![1579698363(1).png](https://pic.leetcode-cn.com/6401d02c6f39a2ad322cad51d9e0fb1a51178117c1c7bcc293e1250423c7e6bf-1579698363\(1\).png)
首先构造一个26个整数的数组arr，每个数组元素存有从a开始的字符在字符串中出现的次数，再构造一个长为26的布尔变量数组inStack用来标记某个字母是否在栈中，接着对string类对象result执行栈操作，遍历字符串s的每个字符，将字符串s的
第i个字符在arr中对应的次数减一，接着将栈result的栈顶与s的第i个字符对比，若栈顶的字符小，则执行push_back()操作，否则result执行出栈操作pop_back()直到栈顶字符小于s中第i个字符，或者栈顶字母对应与arr中的值为0。
最终的栈即为结果。
### 代码

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result = "";
	int arr[26];
	bool inStack[26];
	for (int i = 0; i < 26; i++)
	{
		arr[i] = 0;
		inStack[i] = false;
	}
	for (int i = 0; i < s.size(); i++)
	{
		arr[static_cast<int>(s.at(i) - 'a')]++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (result.size() == 0)
		{
			result.push_back(s.at(i));
			inStack[static_cast<int>(s.at(i) - 'a')] = true;
            arr[static_cast<int>(s.at(i) - 'a')]--;
		}
		else
		{
			if (inStack[static_cast<int>(s.at(i) - 'a')])
			{
				arr[static_cast<int>(s.at(i) - 'a')]--;
				continue;
			}
			else if (static_cast<int>(s.at(i) - result.at(result.size() - 1)) > 0)
			{
				arr[static_cast<int>(s.at(i) - 'a')]--;
				result.push_back(s.at(i));
				inStack[static_cast<int>(s.at(i) - 'a')] = true;
			}
			else
			{
				while (result.size() > 0)
				{
					if (static_cast<int>(result.at(result.size() - 1) - s.at(i)) > 0)
					{
						if (arr[static_cast<int>(result.at(result.size() - 1) - 'a')] > 0)
						{
							inStack[static_cast<int>(result[result.size() - 1] - 'a')] = false;
							result.pop_back();
						}
						else
						{
							
							break;
						}
					}
					else break;
				}
				result.push_back(s.at(i));
				inStack[static_cast<int>(s.at(i) - 'a')] = true;
				arr[static_cast<int>(s.at(i) - 'a')]--;
			}
		}
	}
	return result;
    }
};
```