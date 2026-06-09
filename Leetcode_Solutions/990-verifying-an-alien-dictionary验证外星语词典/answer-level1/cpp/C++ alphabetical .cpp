成功
显示详情 
执行用时 : 4 ms, 在Verifying an Alien Dictionary的C++提交中击败了100.00% 的用户
内存消耗 : 9.1 MB, 在Verifying an Alien Dictionary的C++提交中击败了90.43% 的用户


按照字母表顺序翻译成英文，然后直接比较就好了= =
```
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        string s="abcdefghijklmnopqrstuvwxyz";
        int i;
        if (words.size()<=1) return true;
        for (i=0;i<words.size();i++)
        {
            for (auto &ch:words[i])
                ch=s[order.find(ch)];
            if (i>0&&words[i]<=words[i-1]) return false;
        }
        return true;
    }
};
```