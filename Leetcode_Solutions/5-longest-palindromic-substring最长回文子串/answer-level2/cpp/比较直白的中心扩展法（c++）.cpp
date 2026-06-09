思路比较直接，时间52ms
```
//中心扩展法
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int left;int right;//左右边界
        int doublePointLen = 0;//--------------
        int doublePointTempLen = 0;//记录以两个点为中心点的
        string doublePointStr;
        string doublePointTempStr;//-----------
        int singalPointLen = 0;//---------------
        int singalPointTempLen = 0;//记录以一个为中心点
        string singalPointStr;
        string singalPointTempStr;//--------------
        for(int sin = 0; sin < s.size(); ++sin)//检索以一个点为中心的回文
        {
            left = sin - 1;
            right = sin + 1;
            while(left >= 0 && right < s.size())
            {
                if(s[left] == s[right])
                {
                    left--;
                    right++;
                }
                else
                    break;
            }
            singalPointTempStr = s.substr(left + 1, right - 1 - left);//(right - 1) - (left + 1) + 1
            singalPointTempLen = singalPointTempStr.size();
            if(singalPointTempLen > singalPointLen)
            {
                singalPointLen = singalPointTempLen;
                singalPointStr = singalPointTempStr;
            }
        }
        for(int dou = 0; dou < s.size(); ++ dou)//检索两个点为中心的回文；从零开始，避免bb这种情况
        {
            if(s[dou] != s[dou + 1])
                continue;
            else
            {
                left = dou - 1;
                right = dou + 2;
                while(left >= 0 && right < s.size())
                {
                    if(s[left] == s[right])
                    {
                        left--;
                        right++;
                    }
                    else
                        break;
                }
                doublePointTempStr = s.substr(left + 1,right - 1 - left);
                doublePointTempLen = doublePointTempStr.size();
                if(doublePointTempLen > doublePointLen)
                {
                    doublePointLen = doublePointTempLen;
                    doublePointStr = doublePointTempStr;
                }
            }
        }
        if(doublePointLen > singalPointLen)返回较长的回文
            return doublePointStr;
        else
            return singalPointStr;
    }
};
```
