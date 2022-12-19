```
class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.length();
        int n = needle.length();
        if(h<n) return -1;
        if(n==0) return 0;
        for(int i=0; i<=h-n; i++)
        {
            string str = haystack.substr(i, n);       //截取和needle同样大小的字符串
            if(str == needle)
                return i;
        }
        return -1;
    }
};
//a.copy(b,3,2),   a.assign(b,3,2),  memcpy(a,b,strlen(n))   memmove(a,b,strlen(n))   a.substr(i, n)

