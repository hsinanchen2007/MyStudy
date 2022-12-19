### 解题思路
贪心 + 二分

### 代码

```cpp
class Solution {
private:
    map<int,vector<int>> str;
public:
    Solution()
    {
        str.clear();
    }
    int lower_bound(vector<int>& now,int last)
    {
        int l = 0 , r = now.size()-1;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(now[mid]>last) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return l;
    }
    //贪心 + 二分
    //判断s是否是t的子序列  首先使用哈希表记录母串t中各个字符出现的位置，然后进行子串匹配
    bool isSubsequence(string s, string t) {
        int len = t.size();
        if(len<s.size()) return false;
        if(len==0 && s.size()==0) return true;
        for(int i=0;i<len;i++)
        {
            str[t[i]-'a'].push_back(i);
        }
        int last;
        for(int i=0;i<s.size();i++)
        {
            if(str[s[i]-'a'].size()==0) return false;
            if(i==0) {
                last = str[s[i]-'a'][0];
            }
            else {
                //在下一个字母中比last下标稍微大的第一个  如果找不到这个下标，那么直接返回false
                vector<int> now = str[s[i]-'a'];
                int p = lower_bound(now,last);
                if(p==now.size()) return false;
                last = now[p];
            }
        }
        return true;
    }
};
```