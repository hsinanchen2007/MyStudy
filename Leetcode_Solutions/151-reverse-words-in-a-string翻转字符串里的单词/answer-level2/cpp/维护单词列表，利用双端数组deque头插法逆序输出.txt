### 解题思路
利用deque可以头插的特性，降低时间复杂度

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r && s[l] == ' ') ++l;
        while(r >= l && s[r] == ' ') --r;

        deque<string> d;
        int i = l;
        while(i <= r)
        {
            if(s[i] == ' ')
            {
                d.push_front(s.substr(l, i - l));
                // cout<<d.front()<<endl;
                while(s[i] == ' ') ++i;
                l = i;
            }
            ++i;
        }

        string retstr = s.substr(l, r - l + 1);
        for(string str : d)
        {
            // cout<<str<<endl;
            retstr += ' ' + str;
        }

        return retstr;
    }
};
```