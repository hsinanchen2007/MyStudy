
``` C++
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> res={1,0};
        int rowLen=0;//记录当前行占用字符
        for(int i=0;i<S.size();i++)
        {
            int cur=widths[S[i]-'a'];
            if(rowLen+cur>100)//当前行占用字符加当前字符大于100，行数加1，当前行占用字符重置为当前字符
            {
                res[0]++;
                rowLen=cur;
            }
            else
                rowLen+=cur;
        }
        res[1]=rowLen;
        return res;
    }
};
```