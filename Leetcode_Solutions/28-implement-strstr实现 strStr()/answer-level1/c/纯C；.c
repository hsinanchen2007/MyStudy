![image.png](https://pic.leetcode-cn.com/ed141896d4d83b6ba6fb975e6aad84e3d7bfb9b378fa755c41c43474299850a3-image.png)

int strStr(char * haystack, char * needle){
    int h,n,i=0;
    h=strlen(haystack);
    n=strlen(needle);
    if(n==0)
        return 0;
    while(i<h&&(i+n-1)<h)
    {
        int length=0;
        while(haystack[i+length]==needle[length]&&length<n)
        {
            length++;
        }
        if(length==n)
        {
            return i;
        }
        i++;
    }
    return -1;
}