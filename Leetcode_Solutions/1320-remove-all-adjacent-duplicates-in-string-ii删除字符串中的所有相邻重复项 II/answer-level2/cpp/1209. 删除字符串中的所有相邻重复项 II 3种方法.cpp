### 解题思路
此处撰写解题思路

### 代码
method 1:纯栈模拟 不出意外的超时
```cpp
//没有灵魂的贪心 + 栈模拟
#include <stack>
#include <deque>
class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<char> myDeque;
        int cnt;
        for(auto c:s)
        {

            cnt = k-1; //cnt:expecting几个
            while(!myDeque.empty() && cnt > 0)
            {
                if(myDeque.back() == c)
                {
                    myDeque.pop_back();
                    cnt--;
                }
                else break;
            }
            //要恢复的情况
            if(cnt >0)
            {
                for(int i = 0; i < k-cnt; ++i) myDeque.push_back(c);
            }
        }

        string res ="";
        while(!myDeque.empty())
        {
            res += myDeque.front();
            myDeque.pop_front();
        }
        return res;
    }
};
```


method 2:转换为记录相同字符出现个数的pair
```cpp
//为提高效率，字符串转pair进行操作
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> myVec;
        if(s.size() == 1) return s;
        int curCnt = 1;
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i] == s[i-1]) 
            {    
                curCnt++;
            }
            else
            {
                myVec.push_back(pair<char,int>(s[i-1], curCnt));
                curCnt = 1;
            }
        }
        myVec.push_back(pair<char,int>(s[s.size()-1],curCnt));

        while(1)
        {
            bool isChanged = false;
            for(vector<pair<char,int>>::iterator ite = myVec.begin(); ite != myVec.end(); ++ite)
            {
                if((*ite).second >= k)
                {
                    (*ite).second -= k;
                    isChanged = true;
                }
                if((*ite).second == 0)
                {
                    myVec.erase(ite);
                    ite--;
                }
            }

            for(vector<pair<char,int>>::iterator ite = myVec.begin()+1; ite != myVec.end(); ++ite)
            {
                if((*(ite-1)).first == (*ite).first)
                {
                    isChanged = true;
                    (*(ite-1)).second += (*ite).second;
                    myVec.erase(ite);
                    ite--;
                }
            }

            if(false == isChanged) break;           
        }
        string res="";
        for(auto m:myVec)
        {
            for(int i = 0; i < m.second; ++i) res += m.first;
        }
        return res;
    }
};

```



method 3:结合两种思路
```cpp
//stack + pair
#include <utility>
#include <deque>
class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char, int>> myDeque;
        int tmp = 0;
        for(auto c:s)
        {
            if(!myDeque.empty() && myDeque.back().first == c)
            {
                tmp = myDeque.back().second + 1;
                myDeque.pop_back();
                if(tmp < k)myDeque.push_back(pair<char,int>(c, tmp));
            }
            else myDeque.push_back(pair<char,int>(c,1));
        }

        string res="";
        int tmpChar;
        while(!myDeque.empty())
        {
            tmp = myDeque.front().second;
            tmpChar = myDeque.front().first;
            for(int i = 0; i < tmp; ++i) res += tmpChar;
            myDeque.pop_front();
        }    
        return res;
    }
};

```