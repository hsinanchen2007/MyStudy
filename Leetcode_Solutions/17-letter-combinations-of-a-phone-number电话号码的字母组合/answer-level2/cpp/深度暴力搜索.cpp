```
class Solution {
public:
    char ss[8][5]={//8个数字建对应的字母
        "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    vector<string> rt;//结果
    string tp;//临时变量
    void dfs(string &digits, int step){
        if(step>=digits.length()){//搜索完毕
            tp[step]=0;//字符串末尾为‘\0'
            rt.push_back(tp);//添加之
            return;
        }
        for(char *p=ss[digits[step]-'2'];*p;p++){//遍历每一个可能取到的字母
            tp[step]=*p;//当前按键得到的字母
            dfs(digits, step+1);//搜索下一个按键数字
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()<=0)///输入可能为空
            return rt;
        tp.resize(digits.length()+1);//输入x个数字，那么字母串长度就该为x
        dfs(digits, 0);//暴力搜索，从下标为0的digits开始搜
        return rt;
    }
};
```
![图片1.png](https://pic.leetcode-cn.com/5cb3ce575596bdffd7a3a6a3bf52c1de321c54532d24f6ab04bc1f5a3a610a0d-%E5%9B%BE%E7%89%871.png)
算是道深搜的常规题吧。每次都忽略了输入可能为空...