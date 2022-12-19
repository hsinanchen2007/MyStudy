### 解题思路
使用滑动窗口的方法勉强通过！！！
### 代码

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        //1、暴力方法超时，可以使用滑动窗口
        // int m=s.size();
        // int sum=0;
        // for(int i=0;i<m;++i)
        // {
        //     unordered_set<int> al;int j;
        //     for(j=i;j<m;++j)
        //     {
        //         al.insert(s[j]);
        //         if(al.size()==3)
        //             break;
        //     }
        //     sum+=(m-j);
        // }
        // return sum;
        //2、滑动窗口方法
        int left=0,right=-1;
        map<char,int> mp{{'a',0},{'b',0},{'c',0}};
        int sum=0,m=s.size();
        while(right<m)
        {
            if(mp['a']>0&&mp['b']>0&&mp['c']>0)
            {
                sum+=(m-right);
                mp[s[left]]--;
                ++left;
            }
            else
            {
                ++right;
                mp[s[right]]++;
            }
        }
        return sum;
    }
};
```