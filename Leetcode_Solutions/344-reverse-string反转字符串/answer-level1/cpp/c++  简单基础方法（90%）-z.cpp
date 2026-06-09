### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]==s[n-1-i])  continue;       //优化
            char t=s[i];
            s[i]=s[n-1-i];
            s[n-1-i]=t;
        }
    }
};
```

### 利用swap

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]==s[n-1-i])  continue;       //优化
            swap(s[i],s[n-1-i]);
        }
    }
};
```