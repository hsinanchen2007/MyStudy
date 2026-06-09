```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int l=0;                  //从末尾向前寻找，若碰到字母就变为1
        for(int i=s.size()-1;i>=0;--i)
        {
            if(s[i] == ' ' && l==0)
            {
                continue;          //处理末尾都是空格的情况
            }else if(s[i] != ' ')
            {
                len+=1;
                l=1;               //碰到字母
            }else{
                break;             //找到最后一个单词就跳出
            }
        }
        return len;
    }
};
```
