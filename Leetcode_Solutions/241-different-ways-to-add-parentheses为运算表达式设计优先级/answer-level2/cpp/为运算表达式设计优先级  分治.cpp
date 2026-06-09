分治算法的题目一定要先把树画出来
Res的作用域范围要分清楚

![为运算符设计优先级.jpg](https://pic.leetcode-cn.com/f01eccc71eb72a0d0b6d4902d5ac1befa8ad9e50026fef539482e6c45d2281fc-%E4%B8%BA%E8%BF%90%E7%AE%97%E7%AC%A6%E8%AE%BE%E8%AE%A1%E4%BC%98%E5%85%88%E7%BA%A7.jpg)



### 代码

```cpp
class Solution
{
public:
    vector<int> partition(string in)//对string不要通过int left right下标进行获取字符操作，先push_back才能获取下表
    { 
        vector<int> res; //每次res进来原来存的数据都会被更新替换掉，重新为空，但是在两个操作符之间上一次的值是可以保存下来的

        for (int i = 0; i < in.size(); i++)
        {
            if (in[i] == '+' || in[i] == '-' || in[i] == '*'){
                //for(int i:res)
                        //cout<<"in is"<<in<<"res is:"<<i<<endl;
                string leftString(in, 0, i);
                string rightString(in, i + 1,in.size()-1);
                vector<int> leftRes = partition(leftString);
                vector<int> rightRes = partition(rightString); //leftRes rightRes都是计算完不含操作符，转化为纯数字的
                //使用vector的原因是函数的返回值要求就是vector

                for (int left : leftRes)
                    for (int right : rightRes){
                        int c = 0;
                        switch (in[i]){ 
                        case '+':
                            c = left + right;
                            res.push_back(c);
                            break;
                        case '-':
                            c = left - right;
                            res.push_back(c);
                            break;
                        case '*':
                            c = left * right;
                            res.push_back(c);
                            break;
                        }

                    }

            }
        }

          if (res.size() == 0){ //res为空说明这个时候还没有运算结果，说明还没有遇到运算符，说明目前的in都是数字字符
                int num = stoi(in); //第一次触底进来的是字符串，要先转化为数字
                res.push_back(num);
            }
            return res; //in递归进来后的string是不含操作符，纯数字的，直接返回到上一层 ，res其实里面每次只保存一个数字
    }
    vector<int> diffWaysToCompute(string input)
    {
            int n = input.size();
            vector<int> result = partition(input);
            return result;
    }
    
};
```