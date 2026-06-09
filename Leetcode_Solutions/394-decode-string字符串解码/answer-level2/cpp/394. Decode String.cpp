### 解题思路
思路看代码就好，注释都写了！

### 代码

```cpp

class Solution
{
public:
	string decodeString(string s)
	{
		stack<int> intStack;     // 只用来存放数字，例如3，2这一类的，用来表示重复字母a或b的次数
		stack<string> strStack;  // 用来存放"["和"]"，和中途生成的临时字符串，例如"aaa"和"bcbc"

		int num = 0;
		string str = ""; // ，声明一个std::string对象，默认变为空，也就是string str = "" 和 string str 是等价的

		// 先是遍历整个输入的字符串s
		for (char ch : s)
		{
			// 一开始如果接收的是数字，则只是数字2或3等数字用来替代原先的0
			// 这个if中的下半部分，是为了处理2[a2[b]]中的a2这个情况
			// 这个情况比3[a]2[bc]这种没有[]嵌套的情况复杂些
			// 这种情况就表示，当前是有数字2，是有字符a，但是不够要重复写2次的
			// 并不是单个字符a，a后面还有字符串要重复写2次
			// 所以就先将a压入字符栈strStk，将str=""
			// 等到后面else if(']')的时候，在'['前面会有字符（因为上一步将字符先压进去了）
			// 也就是暂时保存有效的信息(字符)
			// 在判断出']'的函数体中，会将str搞完整，把a和后面已经重复好的字符串“bb”加在一起！
			if (ch >= '0' && ch <= '9')
			{
				num = num * 10 + (ch - '0');

				if (str.length() != 0)
				{
					strStack.push(str);
					str = "";
				}
			}

			// 只有在碰到"["的时候，"["前面的num才会被压入intStk栈中
			// 同时，"["也要压入strStk栈中
			else if (ch == '[')
			{
				intStack.push(num);
				num = 0;

				strStack.push("[");
			}

			// 这一步是启动，开始真正的计算！
			else if (ch == ']')
			{
				while (true)
				{
					// 把范围内的字符串是只有1个还是有2个或以上

					if (strStack.top() == "[")
					{
						strStack.pop();
						break;
					}

					// "3[a2[c]]"这种字符a后面没有紧跟"]"，而是数字的，就是进入下面这种处理方式
					// "3[a]2[bc]"和"2[abc]3[cd]ef"就不用
					str = strStack.top() + str;
					strStack.pop();
				}

				// 取出要重复的次数num
				num = intStack.top();
				intStack.pop();

				// 重复需要“复制”的字符"串"
				string tempAns;
				for (int i = 0; i < num; i++)
				{
					tempAns = tempAns + str;
				}

				// 得到完整的tempAns后，则将num和str归0
				num = 0;
				str = "";

				// 将tempAns这个临时结果压入字符栈strStk中
				strStack.push(tempAns);
			}

			else
				// 当前这个字符是英文字母，a或b
				// 英文字母就只是存储到字符串str中，不压入任何栈
				str = str + ch;
		}

		
        // 本来我新建立一个ans来作为答案，但是错了，这样处理不了
        // 像"2[abc]3[cd]ef"这种尾巴还有字符的情况
        /* string ans; */
		while (!strStack.empty())
		{
            // 本来像aaabcbc是倒着的，但是下面这个式子
            // 就能"正着输出"！
            // 不需要早上听课的呢样，多建立一个栈来“倒序输出”
            // 重点是，这种情况，不仅能让原本会“倒着输出”的栈
            // “正着输出”。
            // 还能处理这种像"2[abc]3[cd]ef"这种尾巴还有字符的情况
			
            // 这个式子神奇的情况在于，strStk.top()是不断更新的
            // str才是上次计算遗留下来的
            // top()计算一次后，会变成下一层的值
            // 以新的top()打头
            // 上次计算好的str放在后面
            // 就刚好可以“顺着输出！”
            // 思想——“将“未取出的”放+号前面，将“遗留的”放+号后面”
            str = strStack.top() + str;
            // ans = strStack.top() + ans;

			strStack.pop();
		}
		return str;
        // return ans;
	}
};
```