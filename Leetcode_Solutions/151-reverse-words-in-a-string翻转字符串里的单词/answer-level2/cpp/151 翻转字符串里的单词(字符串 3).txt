```
class Solution {
public:
    //首先不考虑前后的空格，只考虑最基本的 the sky is blue怎么按照单词级别翻转
    //技巧：翻转两次，第一次就是只按字母级别翻转，结果是eht kys si eulb
    //翻转第二次完全翻转 结果是:blue is sky the




    //其次就是单词前或者单词中间会有不止一个的空格,就是从某一点开始找到一段:也就是说
    //int j=i;在字符串中找一段不是空格的字符段(这个思路和38题相似)
    //while(j<s.size()&&s[j]!=' ')  j++;
    
    string reverseWords(string s) {
        //首先先把多余的空格压缩掉
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            //找空格
            while(i<s.size()&&s[i]==' ') i++;//i找到第一个不是空格的地方
            if(i==s.size()) break;
            
            int j=i;
            while(j<s.size()&&s[j]!=' ') j++;
            reverse(s.begin()+i,s.begin()+j);

            //然后再把这段赋到k上去
            if(k) s[k++]=' ';//首先先隔一个空格
            while(i<j)
            {
                s[k++]=s[i++];
            }

        }
        s.erase(s.begin()+k,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};
```
