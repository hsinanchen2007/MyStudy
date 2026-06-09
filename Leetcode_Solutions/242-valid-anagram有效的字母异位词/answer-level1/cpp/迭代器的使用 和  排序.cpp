刚自学了迭代器的使用，于是写了一下
```
**class Solution 
{
public:
    bool isAnagram(string s, string t)
     {
        if(s.size()!=t.size())
        { 
            return false;
        }
        int a[26]={0};
        int b[26]={0};
        for(string::iterator it1=s.begin();it1!=s.end();it1++)
        {
            a[*it1-'a']++;
        }for(string::iterator it2=t.begin();it2!=t.end();it2++)
        {
            b[*it2-'a']++;
        }int ln=0;
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                ln++;break;
            }
        }return ln==0?true:false;
    }
};**
```
以及第二种方法,先将字符串排序，再比较

```
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        { 
            return false;
        }sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};
```


