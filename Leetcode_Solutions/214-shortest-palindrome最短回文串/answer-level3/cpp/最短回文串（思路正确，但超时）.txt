其实就是官网题解的暴力法~
1）先将字符串反转为 str，
2）然后在反转后的字符串 str 末尾找到与源字符串 s 开头相同的子串，将开始相同的位置记为pos,
3）最后反转后的字符串 str 的pos位置后的字符串替换为源字符串 s。
class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.size();
		string str=s;
		reverse(str.begin(), str.end());
		int i = 0;
		int j = 0;
		while (str[i] != '\0')
		{
			if (str[i] == s[j])
			{
				i++;
				j++;
			}
			else
			{
				i=i-j+1;
				j = 0;
			}
		
		}
		str.replace(i-j, len, s);
		return str;
    }
};