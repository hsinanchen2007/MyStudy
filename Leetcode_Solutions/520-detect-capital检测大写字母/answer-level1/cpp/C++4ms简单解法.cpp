```c++ []
class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;        //记录大写字母的个数
        for(int i=0;i<word.size();i++)
            if(isupper(word[i]))count++;
        if(count==0||count==word.size()||count==1&&isupper(word[0]))return 1;
        else return 0;
    }
};
```