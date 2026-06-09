### 解题思路
这段代码我原封不动提交了两次，第一次4ms，第二次0ms，之间尝试了递归，但效果太不好，空间时间都是10%以下。

思路：一开始觉得这个很简单，多重循环就行，但是想到这个题目的难点在于不确定循环的次数（这样一说好像可以用while循环解决，但是我没有尝试）。
借鉴队列的思想，把digits和最终的结果（res）都视为一个队列，先根据digits的第一个数初始化res，假如输入的是“23”，第一个数字是2，那么res现在有三个变量，分别是“a”，“b”，“c”，进行下一步前将digits第一个数字抹去；每次，从res中取出队头，同时看digits的队头是哪个数字，根据数字字母对照关系在取出的res队头后面继续加元素，再入队（在例子中就是“a”+“d”，入队；“a”+“e”入队；“a”+“f”入队；“b”+“d”入队；“b”+“e”入队；“b”+“f”入队）。
一次处理完之后要将digits的队头抹去。

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string>res;
        string tmp;
        switch (digits[0]) {
            case '2':
                res.push_back("a");
                res.push_back("b");
                res.push_back("c");
                break;
            case '3':
                res.push_back("d");
                res.push_back("e");
                res.push_back("f");
                break;
            case '4':
                res.push_back("g");
                res.push_back("h");
                res.push_back("i");
                break;
            case '5':
                res.push_back("j");
                res.push_back("k");
                res.push_back("l");
                break;
            case '6':
                res.push_back("m");
                res.push_back("n");
                res.push_back("o");
                break;
            case '7':
                res.push_back("p");
                res.push_back("q");
                res.push_back("r");
                res.push_back("s");
                break;
            case '8':
                res.push_back("t");
                res.push_back("u");
                res.push_back("v");
                break;
            case '9':
                res.push_back("w");
                res.push_back("x");
                res.push_back("y");
                res.push_back("z");
                break;
                
            default:
                break;
        }
        for(int i=0;i<n-1;++i)
        {
            int m=res.size();
            switch (digits[i+1]) {
                case '2':
                    for(int j=0;j<m;++j)
                    {
                        tmp=res.front();
                        res.erase(res.begin());
                        res.push_back(tmp+"a");
                        res.push_back(tmp+"b");
                        res.push_back(tmp+"c");
                        
                    }
                    break;
                case '3':
                    for(int j=0;j<m;++j)
                    {
                        tmp=res.front();
                        res.erase(res.begin());
                        res.push_back(tmp+"d");
                        res.push_back(tmp+"e");
                        res.push_back(tmp+"f");
                        
                    }
                    break;
                case '4':
                    for(int j=0;j<m;++j)
                    {
                        tmp=res.front();
                        res.erase(res.begin());
                        res.push_back(tmp+"g");
                        res.push_back(tmp+"h");
                        res.push_back(tmp+"i");
                        
                    }
                    break;
                case '5':
                    for(int j=0;j<m;++j)
                    {
                        tmp=res.front();
                        res.erase(res.begin());
                        res.push_back(tmp+"j");
                        res.push_back(tmp+"k");
                        res.push_back(tmp+"l");
                        
                    }
                    break;
                case '6':
                    for(int j=0;j<m;++j)
                    {
                        tmp=res.front();
                        res.erase(res.begin());
                        res.push_back(tmp+"m");
                        res.push_back(tmp+"n");
                        res.push_back(tmp+"o");
                        
                    }
                    break;
                case '7':
                    for(int j=0;j<m;++j)
                    {
                        tmp=res.front();
                        res.erase(res.begin());
                        res.push_back(tmp+"p");
                        res.push_back(tmp+"q");
                        res.push_back(tmp+"r");
                        res.push_back(tmp+"s");
                        
                    }
                    break;
                case '8':
                    for(int j=0;j<m;++j)
                    {
                        tmp=res.front();
                        res.erase(res.begin());
                        res.push_back(tmp+"t");
                        res.push_back(tmp+"u");
                        res.push_back(tmp+"v");
                        
                    }
                    break;
                case '9':
                    for(int j=0;j<m;++j)
                    {
                        tmp=res.front();
                        res.erase(res.begin());
                        res.push_back(tmp+"w");
                        res.push_back(tmp+"x");
                        res.push_back(tmp+"y");
                        res.push_back(tmp+"z");
                        
                    }
                    break;
                    
                default:
                    break;
            }
        }
        return res;
    }
};
```