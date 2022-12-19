//运行结果：执行用时 :8 ms 内存消耗 :8.6 MB
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = s.length();//获得输入字符串的长度
		if (len == 0)//空字符串，直接返回
		{
			return 0;
		}
		int maxlen = 0,startIndex=0,endIndex=0;//maxlen记录无重复字符串的最大长度
		for (endIndex = 0; endIndex < len; )//endIndex记录当前字符下标
		{
			char ch = s.at(endIndex);//获得当前位置上的字符
			int maxlentmp = 0;
			for (int j = startIndex; j < endIndex; j++)//判断0-(endIndex-1)中是否有当前字符出现
			{
				if (ch==s.at(j))//判断是否有重复字符出现
				{
					startIndex = j + 1;//记录位置
					maxlentmp = endIndex - startIndex;//记录长度
					break;//有相同元素，以s.at(i)开头的元素已经确定无需再查
				}
				maxlentmp++;
			}
			endIndex++;
			maxlentmp++;
			maxlen = max(maxlen, maxlentmp);
		}
		return maxlen;
	}
};