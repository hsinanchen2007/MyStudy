因为感觉自己递归回溯学的不太好，所以这道题尝试用递归的方法来做。
基本思路就是每次比较首尾两个元素，如果相等就向内继续比较首尾两个元素。
int strStr(string haystack, string needle) {
```
代码块
```
    int strStr(string haystack, string needle) {
        if (needle == ""|| haystack == needle)
            return 0;
        if (haystack == ""||haystack.length()<needle.length())
            return -1;
        int len = needle.length();
        for (int i = 0; i <= haystack.size() - len; i++)
        {
            if (haystack[i] == needle[0] && haystack[i + len-1] == needle[len-1])
            {
                if (strStr(haystack.substr(i + 1, len - 2), needle.substr(1, len - 2)) != -1)
                {
                    return i;
                }

            }
        }
        return -1;
    }