一开始没有想到用栈或者队列，直接新建了一个数组，用来保存每一轮的数据


```
class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        int len=ops.size();
        vector<int> q(len,0);
        int sum=0;
        for(int i=0;i<len;i++)
        {
            if(ops[i]=="C")
            {
                q[i]=0;
                int temp=i;//新建临时变量用来循环
                while(q[temp]==0)//找到上一个不为0的数据
                {
                    temp--;
                }
                q[temp]=0;//上一个不为0的数据归零
            }
            else if(ops[i]=="D")
            {
                int temp=i;
                while(q[temp]==0)
                {
                    temp--;
                }
                q[i]=q[temp]*2;
            }
            else if(ops[i]=="+")
            {
                int temp=i;
                while(q[temp]==0)
                {
                    temp--;
                }
                q[i]=q[temp];
                temp--;
                while(q[temp]==0)
                {
                    temp--;
                }
                q[i]+=q[temp];
            }
            else
            {
                stringstream ss;
                ss<<ops[i];
                ss>>q[i];
            }     
        }
        
        for(int i=0;i<len;i++)
        {
            sum+=q[i];
        }
        return sum;
    }
};
```
