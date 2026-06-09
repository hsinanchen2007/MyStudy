### 解题思路
1.
![image.png](https://pic.leetcode-cn.com/51579487e8a26d474608afd3f758fea7296fce636d47eabd048008f879417b2d-image.png)

### 代码

```cpp
class Solution {
public:
    void reverse(string &s,int l, int r)
    {
        while(l<r)
        {
            char tmp=s[l];
            s[l]=s[r];
            s[r]=tmp;
            l++;
            r--;
        }
    }
    string reverseLeftWords(string s, int n) {
        if(s=="") return "";
        int len=s.size();
        n=n%len;
        reverse(s,0,n-1);
        reverse(s,n,len-1);
        reverse(s,0,len-1);
        return s;
    }
};
```



2.
![image.png](https://pic.leetcode-cn.com/0eb778c3560bf8c27b4eda1133088538d5bf2d01b37a3e89af1e30518371782d-image.png)


### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n, s.length() - n) + s.substr(0,n);
    }
};
```