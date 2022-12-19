博客地址：[https://blog.csdn.net/wuzhongqiang/article/details/103289225](https://blog.csdn.net/wuzhongqiang/article/details/103289225)
#### 1. 思路一 - 基于排序
这个是我的初始思路，就是给两个字符串排序，如果是字母异位词，两个字符串应该相等，否则，就不是，所以这个用C++实现，代码挺短的。

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s!=t)
            return false;

        return true;

    }
};
```
这个思路比较清晰，但是时间复杂度有点高，涉及到了两次排序，时间复杂度O(nlogn)。

#### 思路二 - 基于map
第一个思路的时间复杂度有点高，所以就又想起了计数的思想， 可以再用map，遍历第一个字符串，用map自增计数，然后遍历第二个字符串，用map自减计数。如果两个是异位字符串，那么最后map 的值应该是0，否则，不是。

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        map <char, int> m;
        int lens = s.size();
        int lent = t.size();

        if (lens != lent)
            return false;

        for (int i =0; i<lens; i++)
        {
            m[s[i]]++;
        }

        for (int i=0; i<lent; i++)
        {
            m[t[i]]--;
        }

        map <char, int>::iterator it;
        for (it=m.begin(); it!=m.end(); it++)
        {
            if (it->second != 0)
                return false;
        }
        return true;
    }
};
```
这个效率要比上面的思路一高一些。

#### 思路三 - 基于数组统计个数
由于这个题里面只说了可以假设都是小写字母，那么只需要统计26个小写字母的个数即可，所以，用一个数组统计会快很多，因为直接基于下标访问，时间复杂度会是O(1)。所以这个效率是最高的。

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;

        int *a = new int[26]();

        for (int i=0; i<s.size(); i++)
        {
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }

        for (int i=0; i<26; i++)
        {
            if (a[i] != 0)
                return false;
        }
        return true;


    }
};
```
但是，这个也要注意，就是适用于都是字母的，如果有Unicode字符，不适用。