### 解题思路
执行结果：通过
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :8.4 MB, 在所有 cpp 提交中击败了90.14%的用户
针对规律复杂化，越复杂消耗应该也是越大的。不会测试（伤）

### 代码

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        std::map<char, std::string> p;   //  为每个单词做权重（用键表示权重）
		int words = 0;
		std::string word;      //  保存字符串对象str中的单词。
		const char *temp = str.c_str();         //  C风格的字符串
		const size_t StrSize = str.size() + 1;  //  常量。表示C风格的字符串的字符个数

		/* str对象要找到单词需要循环。 
		   疑问：
		       使用基于范围的for循环不知道怎么找到结尾而不跳出以期把最后一个单词判断出来  */
		for (size_t i = 0; i < StrSize; ++i)   
		{
			if (temp[i] != ' ' && temp[i] != '\0')    //  在str中单词以一个空格分隔的
			{
				word.push_back(temp[i]);
			}
			else              //  找到一个单词后，需要赋予权重（与规律的规则对应）
			{
				if (words == pattern.size())   //  防止words超出pattern的范围。单词还没有判断完权重，所以比实际少1。
					return false;

				char ch = pattern[words];  //  规律的每一个规则，规律与单词一一对应在下标位置上
				if (p[ch].empty())     //  如果为空，第一次循环表示初始化。
				{
                    for (auto ppair : p)      //  判断单词是否被重复赋予权重。
					{
						if (ppair.second == word)
							return false;
					}	                      //  想了好久没有好办法，这就是我的最好办法了。
                    
					p[ch] = word;
					//word.clear();    //  word（单词）需要清除。但因还有其他情况所以延后
				}
				else                   //  如果不为空，表示ch与前面有相同规则。
				{
					if (p[ch] != word)   //  对应的str单词应该是相同的，表示规则相同。
					{
						return false;    // 否则就是没有规律。
					}
				}
				word.clear();   //  清理单词，以备下一次使用。
				++words;    //  记录单词个数。
			}
		}
		if (words != pattern.size())   //  防止words小于pattern的字符数。
			return false;

	    return true;
    }
};
```