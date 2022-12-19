### 解题思路
**思路这么多人都写，我也是看的别人
闲得没事，在自己电脑上写了下添加括号后的表达式**


![image.png](https://pic.leetcode-cn.com/fdcf40a0874136127c19c68e825c4dbdf47607c710266754e360f015072803f1-image.png)
**结果没排序**

### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int num;
    string exp;
    Node(int n,string e):num(n),exp(e){}
};

class Solution {
    map< pair<int,int>, vector<Node> >hash;  // 备忘录  key: <left,right>
public:
    vector<Node> ways(const string &input, int left, int right)
    {
        pair<int,int>curKey(left, right);
        if(hash.find(curKey) != hash.end())
        {//之前存了
            return hash[curKey];
        }
        vector<Node> res;
        for(int i = left; i < right; i++)
        {
            if(input[i] == '-' || input[i] == '+' || input[i] == '*')
            { //遇到操作符分别递归计算左边、右边,
              //当前选择的操作符优先最低(递归的下一层的表达式先算)
                vector<Node>left_result = ways(input, left, i);
                vector<Node>right_result = ways(input, i+1, right);

                for(int ii = 0; ii < left_result.size(); ii++)
                {
                    for(int jj = 0; jj < right_result.size(); jj++)
                    {
                        int num = cal(input[i], left_result[ii].num, right_result[jj].num);
                        string exp = "(" + left_result[ii].exp + " " + input[i] + " "+ right_result[jj].exp + ")";
                        res.push_back(Node(num, exp));
                    }
                }
            }
        }
        if(res.size() == 0)
        {//我的编译器用不了C++ 11, 所以用不了stoi,这里用int atoi(const char *str);
		//c_str(): string -> char *str 
            int num = atoi(input.substr(left, right - left).c_str());
            string exp = input.substr(left, right - left);
			res.push_back(Node(num, exp)); 
        }
        hash[curKey] = res;
        return res;
    }
    int cal(char ops, int a, int b)
    {
        int res;
        switch(ops)
        {
            case '-': res = a - b; break;
            case '+': res = a + b; break;
            case '*': res = a * b; break;
        }
        return res;
    }
    vector<Node> diffWaysToCompute(string input) {
        return ways(input, 0, input.size());
    }
};
int main() 
{ 
    string input = "5*4-3*2"; 
    Solution s;
    vector<Node> res = s.diffWaysToCompute(input);  
  
    for (int i = 0; i < res.size(); i++) 
        cout <<res[i].exp<<" = "<< res[i].num<<endl; 
    return 0; 
} 
```