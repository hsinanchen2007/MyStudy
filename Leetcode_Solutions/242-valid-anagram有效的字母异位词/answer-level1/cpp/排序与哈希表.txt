方法1：哈希表

```
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        map<char, int> map;
        
        for(int i=0; i<s.length(); i++){
            
            map[s[i]] += 1;
        }
        
        for(int i=0; i<t.length(); i++){
            
            if(map[t[i]] <= 0)
                return false;
            else
                map[t[i]] -= 1;

        }
        
        return (s.length()==t.length());
    }
};
```

方法2：排序

```
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return(s==t);
    }
};
```

方法3：容器版本的哈希表

这里不用数组的原因是因为数组直接不能通过“==”运算符直接比较大小。

```
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length())
            return false;
        
        vector<int> S(26,0);
        vector<int> T(26,0);
        
        for(int i=0; i<s.length(); i++){
            
            S[s[i] - 'a']++;
            T[t[i] - 'a']++;
        }

        return (S==T);
    }
};
```
