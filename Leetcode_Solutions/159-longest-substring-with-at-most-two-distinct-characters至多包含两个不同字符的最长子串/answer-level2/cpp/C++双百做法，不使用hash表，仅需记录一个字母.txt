C++双百做法，不用哈希表，也不用滑动窗口，仅记录符合条件的子串长度
```
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty())
            return 0;
        int tmp1=1; //记录连续字母长度
        int tmp2=0; //记录变换字母前只包含两个不同字符子串的长度
        char tmp_c=s[0];//记录上一次出现的不同字母,当出现不一样字母时tmp_cd为其前一个字母
        int ret=1;//返回值
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])//增加连续字母长度
                tmp1++;
            else if(s[i]==tmp_c)//当不与前一个字母相同，但是与记录的字母相同时
            {
                tmp2+=tmp1;//将之前的包含两个不同字母的子串长度更新
                tmp1=1;     //重置连续相同字母的长度
                tmp_c=s[i-1];//更新上一次出现的不同字母
            }
            else//当不与前一个字母相同，并且不与记录的字母相同
            {
                tmp2=tmp1;
                tmp1=1;
                tmp_c=s[i-1];
            }
            ret=max(ret,tmp1+tmp2);
        }
        return ret;
    }
};
```

