### 解题思路
用了两种方法，第一个方法是递归，但是超时没有通过，就采用下面的第二种方法：
1、先遍历一遍字符串，用一个map<char, vector<int>>来存储每个字符及出现的位置
2、遍历字符串，从dict查出字符出现的位置，然后判断两个位置之间是否回文

备注：其实在方案二的基础上还可以优化下，直接遍历dict，下面代码写差不多了，不过没有跑过（还需要特殊的处理，1）前面判断s长度小于大于1的时候，直接返会s）
### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        
        map<char, vector<int>> dict;
        for ( int i = 0; i < s.length(); i++ )
        {
            char a = s[i];
            map<char, vector<int>>::iterator it = dict.find(a);
            if ( it == dict.end() )
            {
                vector<int> v; 
                v.push_back(i);
                dict[a] = v;
            }
            else
            {
                it->second.push_back(i);
            }
        }

        string sublogest;
        //方案二
        for ( int i = 0; i < s.length(); i++ )
        {
            if ( (s.length() - i) <= sublogest.length()) break;
            map<char, vector<int>>::iterator it = dict.find(s[i]);
            string ts = findSubLongest(s, i, it->second, sublogest.length());
            if ( ts.length() > sublogest.length() )
            {
                sublogest = ts;
            }
            
        }
        /* 方案三
        for (map<char, vector<int>>::iterator it = dict.begin(); it!=dict.end();it++)
        {
            char a = it->first;
            vector<int> &vidx = it->second;
            if ( vidx.size() <= 1 ) continue; 
            int maxpos = vidx[vidx.size()-1];
            for ( int i = 0; i < vidx.size(); i++)
            {
                int bs = vidx[i];
                if ( (maxpos-bs+1) < sublogest.length() ) break;
                for ( int j = vidx.size() -1; j >i; j--)
                {
                    printf("===2 %c mp:%d, ml:%d <%d, %d>\n", maxpos, sublogest.length(), i, j)
                    int be = vidx[j];
                    if ( (be - bs + 1) < sublogest.length() ) break;
                    if ( checkIsPalindrome(s, bs, be) )
                    {
                        printf("### find ok:b=%d, e=%d\n", b, idx);
                        return s.substr(b, idx-b+1);
                    }
                }
            }
        }
        */
        return sublogest;
    }

    string findSubLongest(string s, int b, vector<int> &vidx, int ml)
    {
        printf("findSubLongest(b:%d ml:%d)\n", b, ml);
        for ( int i = vidx.size() -1; i >= 0; i--)
        {
            int idx = vidx[i];
            //printf("==(b:%d idx:%d)\n", b, idx);
            if (idx < b ) return "";
            if ( (idx-b+1) <= ml ) return "";
            if ( checkIsPalindrome(s, b, idx) )
            {
                //printf("### find ok:b=%d, e=%d\n", b, idx);
                return s.substr(b, idx-b+1);
            }
        }
        return "";
    }

    bool checkIsPalindrome(string s, int b, int e)
    {
        while( (b<e) && (s[b]==s[e])) 
        {
            b++; e--;
        }
        return b >= e;
    }
};
```