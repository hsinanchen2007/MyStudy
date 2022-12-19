bf
```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j=0,n=haystack.size(),m=needle.size();
        while(i<n && j<m){
            if(haystack[i]==needle[j])
            {i++;j++;}
            else
            {i-=j-1;j=0;}
        }
        if(j==m)
            return i-j;
        return -1;
    }
};
```


kmp
```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        int i=0,j=0,n=haystack.size(),m=needle.size();
        int *next=getNext(needle);
        while(i<n && j<m){
            if(j<0 || haystack[i]==needle[j])
                i++,j++;
            else
                j=next[j];
        }
        if(j==m)
            return i-j;
        return -1;
    }
    int *getNext(string p){
        int m=p.size(),j=0;
        int *next=new int[m];
        int t=next[0]=-1;
        while(j<m-1){
            if(t<0 || p[t]==p[j])
                next[++j]=++t;
            else
                t=next[t];
        }
        return next;
    }
};
```