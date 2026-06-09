### 解题思路
代码来自评论区大佬

C++中 **stoi**函数：将 n 进制的字符串转化为十进制
C++11 **auto**：可以在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型
思路：
  第一层递归： 2-1-1 分为 2（res1） 和 - 和 1-1（res2）
  第二层递归： 2没有运算符，不会进入if语句，res为空，被转换为数字 返回
               1-1分为 1 和 - 和 1  进入第三层
  第三层递归： 第四层递归返回后， 1 进入res1,1进入res2， 执行res.push_back(r1-r2);返回 0
  第二层返回：res1中是2，res2中是0 执行res.push_back(r1-r2) 返回结果2到第一层


### 代码

```cpp
class Solution {
public:

    vector<int> diffWaysToCompute(string input) {
        vector<int>res;
        for(int i=0;i<input.size();i++){
            char c=input[i];
            if(c=='+'||c=='-'||c=='*'){
                auto res1=diffWaysToCompute(input.substr(0,i));
                auto res2=diffWaysToCompute(input.substr(i+1));
                for(auto r1:res1){
                    for(auto r2:res2){
                        if(c=='+'){
                            res.push_back(r1+r2);
                        }
                        if(c=='-'){
                            res.push_back(r1-r2);
                        }
                        if(c=='*'){
                            res.push_back(r1*r2);
                        }
                    }
                }
  
            }
        }
        if(res.size()==0){
            res.push_back(stoi(input));
        }
        return res;
    }
};
```