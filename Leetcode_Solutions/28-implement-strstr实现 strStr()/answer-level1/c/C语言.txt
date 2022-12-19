### 解题思路
此处撰写解题思路

### 代码
![搜狗截图20200325115722.png](https://pic.leetcode-cn.com/d1572090a6c9949fa9d5587560d2f848be04c1b7a872938193ab045f3147634e-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20200325115722.png)
```c
int strStr(char * haystack, char * needle){
    int len1,len2;
    int i=0,j=0,k=0;
    len1=strlen(haystack);len2=strlen(needle);
    if(len2>len1) return -1;
    else if(len2==0) return 0;
    else{
        while(i<len1&&j<len2){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                k++;
                i=k;
                j=0;
            } 
        }
        if(j==len2){
            return i-len2;
        }
        else return -1;
    }
}
```