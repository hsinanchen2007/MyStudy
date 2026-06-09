代码有注释，应该很好理解
```C++ []
class Solution {
private:
    vector<string> res;
    vector<string> nowword;
    int n;
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i;
        int wordlen;
        n=words.size();
        int nowwordlen=0;
        int nownum=0;
        int leftblank;
        int blank;
        string temp;
        i=0;
        while(i<n)
        {
            wordlen=words[i].length();
            if(nowwordlen+nownum+wordlen<=maxWidth)         //判断能否放入
            {
                nowword.push_back(words[i]);
                nowwordlen+=wordlen;
                nownum++;
                i++;
            }
            else
            {
                if(nownum==1)                               //如果只有一个单词左对齐
                {
                    temp=words[i-1];
                    for(int j=0;j<maxWidth-words[i-1].length();j++)
                    {
                        temp+=' ';
                    }
                    res.push_back(temp);
                    temp="";
                }
                else                                         //多个单词
                {
                    leftblank=(maxWidth-nowwordlen)%(nownum-1);         //左边放置空格多于右边的数量
                    blank=(maxWidth-nowwordlen)/(nownum-1);             //若正好每个空格应放多少" "
                    int j=0;
                    while(leftblank-->0)
                    {
                        temp+=nowword[j];
                        for(int z=0;z<blank+1;z++)
                        {
                            temp+=' ';
                        }
                        j++;
                    }
                    while(j<nownum-1)                               //  -1最后一个单词没有空格
                    {
                        temp+=nowword[j];
                        for(int z=0;z<blank;z++)
                        {
                            temp+=' ';
                        }
                        j++;
                    }
                    temp+=nowword[j];       
                    res.push_back(temp);
                    temp="";
                }
                nowword.clear();                            //置初值
                nowwordlen=0;
                nownum=0;
            }
        }
        int j=0;
        while(j<nownum-1)                                   //最后一行左对齐
        {
            temp+=nowword[j];
            temp+=' ';
            j++;
        }
        temp+=nowword[j];
        int len=maxWidth-temp.length();
        for(int z=0;z<len;z++)
            temp+=' ';
        res.push_back(temp);
        return res;
    }
};
```

