如下，利用迭代器和reverse函数可以轻松解决

```c++ []
string reverseWords(string s) {
    for (string::iterator start=s.begin(),end = s.begin() + 1; end < s.end(); end++) 
        if (*end == ' ')  reverse(start, end),start = end+1;
        else if (end + 1 == s.end())  reverse(start, end+1);
    return s;
	}
```
