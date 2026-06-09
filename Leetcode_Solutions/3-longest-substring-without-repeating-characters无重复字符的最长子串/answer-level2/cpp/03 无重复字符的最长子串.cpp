1. 方法一：暴力法:两层for循环依次将两个及以上的子串取出来，判断每一个子串中是否有重复字符(时间复杂度O(n^3))
        因为时间复杂度太高，会超时。
```
class Solution {
public:
    bool allunique(string s, int begin, int end)//判断子串中是否有重复字符
	{
		set<char> myset;
		int i = begin;
		while (i <= end)
		{
			if (myset.count(s[i]))
			{
				return false;
			}
			myset.insert(s[i]);
			i++;
		}
		return true;
	}


    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0 || s.size() == 1)//特殊判断：当输入空字符串是返回值是0，一个字符的字符串返回值是1
		{
			return s.size();
		}
		int result=1;
		int length = s.size();
		for (int i = 0; i < s.size() - 1; i++)//两层循环依次取出子串
		{
			for (int j = i + 1; j < s.size(); j++)
			{
				if (allunique(s, i, j))
				{
					result = max(result, j - i + 1);
				}
			}
		}
		return result;
    }
};
```


2. 方法二：滑动窗口


```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //滑动窗口
        set<char> myset;
        int result=0;
        int i=0;
        int j=0;
        while(i<s.size()&&j<s.size())
        {
            if(!myset.count(s[j]))
            {
                myset.insert(s[j]);
                j++;
                result=max(result,j-i);
            }
            else
            {
                auto temp=myset.find(s[i]);
                myset.erase(temp);
                i++;
            }
        }
        return result;
    }
};
```
