借鉴了评论区大佬的思路，做了点小改动，内存消耗降低明显。
每次只处理当前按键的情况，遍历一遍
时间复杂度O(4^n)
```
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> a{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> c;
        if(digits.empty())
            return c;
        c.push_back("");
        for (int i=0;i<digits.size();i++)
        {
            int res=digits[i]-'2';//当前按键对应的字符串索引
            int len=c.size();     //前一次处理好的字符串数
            for(int i = 0;i<len;i++)//遍历前一次处理好的字符串
            {
                for (auto m:a[res])//遍历按键对应字符
                {
                    c.push_back(c[i]+m);//将每一种组合放到末端
                }
            }
            c.erase(c.begin(),c.begin()+len);//清除前一次的组合
        }
       return c;
    }
};

  
```
