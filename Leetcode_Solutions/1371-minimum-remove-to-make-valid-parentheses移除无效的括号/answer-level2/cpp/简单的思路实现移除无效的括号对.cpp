**思路：**
这个题目思路比较简单。
1、从左到右，遍历字符串，如果是），则判断当前有有多少个（，如果（的数目大于等于）的数目。则不添加。其他情况，原样复制至新串。
2、在新串中，从右向左遍历。由于第一步已经统计出了（的数目和)的数目，直接删除多余数目的（。
3、对新串进行翻转（第二步使用push_back,导致字符串被翻转了，需要翻转回来。）、

**结果**
![QQ图片20200107225145.png](https://pic.leetcode-cn.com/386fdf7e31020dc4471bc46e3a62474c74cb0dc6c78341a00a427bc973d2cdcb-QQ%E5%9B%BE%E7%89%8720200107225145.png)

**代码：**
```
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int leftCnt=0,rightCnt=0;
        string tempString;
        for(auto ch : s)
        {
            if (ch=='(')
            {
                    ++leftCnt;
                    tempString.push_back(ch);
            }
            else if (ch==')')
            {
                 ++rightCnt;
                if (rightCnt>leftCnt)
                {
                    //delete right==donot push
                    --rightCnt;
                }
                else
                {
                    tempString.push_back(ch);
                }
            }
            else 
                tempString.push_back(ch);
        }
        /*there are two way to solve,
            1:right scan ,delete the extral (,and inverse the string
            2:right scan,delete delete the extal (,and inverse the string; in this way ,we                  alread know the number of extral (,just delete ( until left==right    
        */
        // //right scan
        // leftCnt=0;
        // rightCnt=0;
        // string temps2;
        // for (auto i=tempString.size();i>0;i--)
        // {
        //     auto ch=tempString[i-1];
        //     if (ch==')')
        //     {
        //             ++rightCnt;
        //             temps2.push_back(ch);
        //     }
        //     else if (ch=='(')
        //     {
        //          ++leftCnt;
        //         if (leftCnt>rightCnt)
        //         {
        //             //delete right==donot push
        //             --leftCnt;
        //         }
        //         else
        //         {
        //             temps2.push_back(ch);
        //         }
        //     }
        //     else 
        //         temps2.push_back(ch);
        // }
        // // inverse the string.
        // string temps3;
        // for (auto i=temps2.size();i>0;i--)
        // {
        //     auto ch=temps2[i-1];
        //     temps3.push_back(ch);      
        // }

        //compare left and right ,then delete extral right,from the bottom
        string temps2,temps3;
        if (leftCnt>rightCnt)
        {
            auto len=tempString.size();
            for (auto i=len;i>0;i--)
            {
                auto ch=tempString[i-1];
                if (ch=='(' && leftCnt>rightCnt)
                {
                    --leftCnt;
                }
                else
                    temps2.push_back(ch);      
            }
            //inverse the string.
            for (auto i=temps2.size();i>0;i--)
            {
                auto ch=temps2[i-1];
                temps3.push_back(ch);      
            }
        }
        else
            temps3=tempString;
        return temps3;
    }
};


