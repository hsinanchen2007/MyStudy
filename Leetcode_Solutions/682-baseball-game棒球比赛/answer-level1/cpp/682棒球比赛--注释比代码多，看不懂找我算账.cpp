```
class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        stack<int> res;
        for(int i=0;i<ops.size();i++)
        {
            //如果不是这三个字符，那么一定是个数字，现在需要把数字的字符串形式转为int类型
            //并且将这个数字，push到栈中进行下一步的操作
            if(ops[i]!="C"&&ops[i]!="D"&&ops[i]!="+")
            {
                int num=0;
                int flag=1;
                for(int j=0;j<ops[i].size();j++)
                {
                    //当第一位置遇到负号，需要更新flag，从1变成-1
                    if(ops[i][j]=='-')
                    {
                        flag=-1;
                        continue;
                    }
                    //字符转成数字的常用方法
                    num=10*num+ops[i][j]-'0';
                }
                num=flag*num;
                res.push(num);
            }
            //其实后续的判空与否都无所谓，因为题目给的操作都是合法的，也就是给C的时候，前面一定有数字
            else if(ops[i]=="C"&&!res.empty())
            {
                //如果碰见C，要清除掉上一轮的成绩
                res.pop();

            }
            else if(ops[i]=="D"&&!res.empty())
            {
                //遇到D，二倍积分存进去
                int temp1=2*res.top();
                res.push(temp1);
            }
            else if(ops[i]=="+"&&!res.empty())
            {
                int temp2=res.top();
                res.pop();
                int temp3=res.top();
                int temp4=temp2+temp3;
                res.push(temp2);
                res.push(temp4);
            }
        }
        int result=0;
        //注意res栈中的元素就是每一轮操作后的数字，需要将他们加起来
        while(!res.empty())
        {
            result+=res.top();
            res.pop();
        }
        return result;
        
    }
};
```
