CPP： 方法一，利用 `str.erase() ，erase` 之后调整 i 和 cnt 的值， for 循环从头遍历s, 但是在 for 循环中，条件语句变为 `!s.empty() && i < s.size()-1 `,否则会报错。
```cpp
class Solution {
public:
    string removeDuplicates(string s, int k) {
        helper(s, k);
        return s;
    }
    
    void helper(string &s, int k) {
        int cnt = 1;
        for(int i = 0; !s.empty() && i < s.size()-1; ++i) {
            if(s[i+1] == s[i]) {
                ++cnt;
                if(cnt == k) {
                    s.erase(i-k+2, k);
                    //erase之后调整 i 和 cnt 的值
                    //for循环从头遍历s
                    i = -1;
                    cnt = 1;
                }
            }
            //不是连续k个字符相同，调整cnt的值
            else {
                cnt = 1;
            }
        }
    }
};
```

方法二：利用递归
```cpp
class Solution {
public:
    string removeDuplicates(string s, int k) {
        helper(s, k);
        return s;
    }
    
    void helper(string &s, int k) {
        int cnt = 1;
        for(int i = 0; i < s.size()-1; ++i) {
            if(s[i+1] == s[i]) {
                ++cnt;
                if(cnt == k) {
                    //cout<<"ok-0 "<<s[i-k+2]<<endl;
                    s.erase(i-k+2, k);
                    //cout<<"ok-1 "<<s<<endl;
                    helper(s, k);
                }
            }
            else {
                cnt = 1;
            }
        }
    }
};
```


