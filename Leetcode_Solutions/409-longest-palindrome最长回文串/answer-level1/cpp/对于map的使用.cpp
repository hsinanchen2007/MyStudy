### 解题思路
执行用时击败100%的用户，开心！
算法：
1、对字符串中出现的字符建立映射，统计出现次数；
2、对于偶数次出现的，直接加入结果；
对于奇数次出现的，-1后加入结果，并报告出现了奇数；
3、循环2至map末尾；
4、如果出现过奇数，结果+1返回；
如果没有出现过奇数，结果返回。

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        /*
        for (int i=0; i<26; i++){
            mp['A'+i]=0;
            mp['a'+i]=0;
        }
        */
        for (int i=0; i<s.size(); i++){
            mp[s[i]]++;//建立映射
        }
        int re=0;
        int flag=0;//是否出现了奇数次
        for(map<char, int>::iterator it=mp.begin(); it != mp.end(); it++){
            if (it->second % 2 == 0) re+=it->second;//偶数直接加入结果
            else{
                re+=it->second - 1;
                flag=1;//出现了奇数次
            }
        }
        if (flag==1) re+=1;
        return re;
    }
};
```