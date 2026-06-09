首先将table表打好
然后建一个temp栈记录
选择第一个数字，写一个for循环遍历table中该字母对应的字符串的字母然后压入temp，当temp满的时候加入结果集
递归搜索下一个数字
退栈
记得写递归结束的判断
ok，上代码
```
class Solution {
public:
    string table[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void getVectorDFS(vector<string> &res,int pressI,string &digits,string &temp)//这是递归函数,深度优先搜索
    {
        if(pressI>=digits.size())//退出递归条件
            return;
        int tableI=digits[pressI]-'0';
        for(int i=0;i<table[tableI].size();i++)
        {
            temp.push_back(table[tableI][i]);
            if(temp.size()==digits.size())
                res.push_back(temp);
            //调用递归搜索
            getVectorDFS(res,pressI+1,digits,temp);
            //退栈换下一个字符
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string temp;
        getVectorDFS(res,0,digits,temp);
        return res;
    }
};
```
