### 解题思路
1、存储第一个数；
2、从第二个数开始，接下来的每一个数都是对上一个数的报数
使用队列实现，将上一个数对应的序列存到队列中，然后从队首依次弹出
3、记录队首的数值以及重复出现的次数，直到队首数值发生改变，将重复出现的次数和队首数值依次push进队列
4、将数字转换成字符串

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        map<int,char>m{{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'}};
        queue<int>q;
        q.push(1);//存初值
        string result;
        int temp = 1,num=0,length;//temp表示队首的值，num表示出现次数，length表示队列长度
        for(int i=2;i<=n;i++)
        {
            length = q.size();
            while(length>0)
            {
                num = 0;
                while(q.front() == temp && length>0)
                {
                    num++;
                    q.pop();
                    length--;
                }
                q.push(num);
                q.push(temp);
                temp = q.front();
            }
        }
        while(!q.empty())//将数字转换成字符串
        {
            result += m[q.front()];
            q.pop();
        }
        return result;
    }
};
```