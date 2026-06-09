执行用时 :**32 ms**, 在所有 C++ 提交中击败了80.89%的用户
内存消耗 :**6.5 MB**, 在所有 C++ 提交中击败了100.00%的用户

时间复杂度: O(n^2)
空间复杂度：O(n)
n为字符串长度

算法思路：
1.遍历字符串的每个字符
2.以每个字符为中心，向两边遍历。判断两边是否对称。
3.若对称，记录子字符串长度。
3.记录最长的子字符串并返回。
PS:需要一个single变量记录子字符串长度是奇数还是偶数。

```
class Solution {
public:
	string longestPalindrome(string s) 
	{
		if (s.length() == 0)
		{
			return "";
		}
        if (s.length() == 1)
		{
			return s;
		}
        //子字符串的长度
        int length = 0;
        //子字符串中心位置
        int center = 0;
        //子字符串长度为奇数还是偶数
        int single = false;

        for(int i = 1;i<s.length()-length;i++)
        {
            int iter = 1;
            while(s[i-iter] == s[i+iter])
            {
                iter++;
                if(i-iter<0 || i+iter>s.size()-1)
                    break;
            }  
            iter--;
            if(iter+1>length)
            {
                center = i;
                length = iter;
                single = false;
            }
            iter=0;
            while(s[i-iter] == s[i+iter-1])
            {
                iter++;
                if(i-iter<0 || i+iter-1>s.size()-1)
                    break;
            }
            iter--;
            if(iter>length)
            {
                center = i;
                length = iter;
                single = true;
            }
        }
        int start = center - length;
        int end = center + length;

        if(!single)
		    return s.substr(start, end - start + 1);
        else
            return s.substr(start, end - start);
	}
};

```
