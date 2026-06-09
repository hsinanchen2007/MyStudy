思路：
1.首先定义一个vector数组
2.给当前的字符串的尾部添加一个空格（防止当前字符串尾部没有空格）
3.获取第一个不是空格的字符
4.循环遍历时，将所有的空格去除后添加到数组中
5.数组的逆向遍历添加到string中并返回。
```
class Solution {
public:
    string reverseWords(string s) {
        vector<string> result;
	    s.push_back(' ');//尾部先添加一个空格
	    int index = 0;
	    for (int i = 0; i < s.length(); i++)//先移除字符串首部的所有空格
	    {
		    if (s[i] != ' ') {
			    index = i;
			    break;
		    }
	    }
	    string temp;
	    for (int i = index; i < s.length(); i++)//将字符串添加到result里面
	    {
		    if (s[i] != ' ') {
			    temp += s[i];
		    }
		    else {
			    if (temp != "") {//如果末尾有多余的空格不要添加进来
				    result.push_back(temp);
				    temp = "";
			    }
		    }
	    }
	    string ans = "";
	    for (int i = result.size() - 1; i >= 0; i--)//反向添加到ans里面，注意如果最后一个字符后面无需添加空格
	    {
		    ans += result[i];
		    if (i != 0)
		    {
			    ans += " ";
		    }
	    }
	    return ans;
    }
};
```
