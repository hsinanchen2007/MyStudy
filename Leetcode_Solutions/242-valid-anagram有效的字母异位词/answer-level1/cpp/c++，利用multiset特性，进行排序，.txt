### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        // multiset<char> s1;
        // multiset<char> s2;

        // int len = s.size();
        // int len2 = t.size();
        // if(len!=len2)  return false;
        // if(len==0&&len2==0)  return true;
        // for (int i = 0;i < len;i++)
        //     s1.insert(s[i]);
        
        // for (int i = 0;i < len2;i++)
        //     s2.insert(t[i]);

        // multiset<char>::iterator it = s1.begin();
        // multiset<char>::iterator itr = s2.begin();
        // while (it != s1.end())
        // {
        //     if ((*it) != (*itr))  return  false;
        //     it++;itr++;
        // }


    //    vector<char>s1;
    //    vector<char>s2;
    //    int len = s.size();
    //    int len2 = t.size();
    //    if(len!=len2)  return false;
    //    if(len==0&&len2==0)  return true;
    //    for(int i=0;i<len;i++)
    //    {
    //        s1.push_back(s[i]);
    //        s2.push_back(t[i]);
    //    }
    //    sort(s1.begin(),s1.end());
    //    sort(s2.begin(),s2.end());
    //     for(int i=0;i<len;i++)
    //     {
    //         if(s1[i]!=s2[i])  return false;
    //     }
    //     return true;
    sort(s.begin(),s.end()); 
    sort(t.begin(),t.end());
    return  s==t;
    }
};
```