`class Solution {
public:
    string reverseWords(string s) {
        if(s.length() == 1)
            return s;
        int lastZero = -1;  //避免第一次翻转时漏掉第一个字母
        string res = "";
        for(int i=0;i<s.length();i++){
            if(s.at(i) == ' '){  //若果遇到了空格
                for(int j=i-1;j>lastZero;j--){
                    char a = s.at(j);
                    res.append(1,a);
                }
                lastZero = i;
                res += ' ';
            }
        }
        /* 最后在对最后一个单词进行翻转 */
        for(int i = s.length()-1;i>lastZero;i--)
            res.append(1,s.at(i));
        return res;
    }
};`