### 解题思路
本来一开始第一反应是二分，后来发现不对，转向分治。确定了分治之后，首先需要考虑的就是枢纽元的选择，这道题比较不一样的地方在于，可能会有多个枢纽元。
所以这里用个数组来保存。想到这里代码就很好写了。

### 代码

```cpp
class Solution {
public:
    int longestSubstring(string s, int k) {
        map<char,int> m;
        for(char c:s)
            m[c]++;
        bool flag=false;
        for(auto ele:m)
        {
            if(ele.second<k)
            {
                flag=true;
                break;
            }
        }
        if(!flag)
            return s.size();
        s.push_back('#');
        m['#']=1;
        vector<string> vec;
        int left=0,right=0;
        while(right<s.size())
        {
            if(m[s[right]]<k)
            {
                vec.push_back(s.substr(left,right-left));
                left=right+1;
            }
            right++;
        }
        int res=0;
        for(string str:vec)
            res=max(res,longestSubstring(str,k));
        return res;
    }
};
```