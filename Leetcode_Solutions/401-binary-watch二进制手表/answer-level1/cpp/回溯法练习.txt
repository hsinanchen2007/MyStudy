### 解题思路

1. **多叉树的回溯法的模板**
2. **编写一个包含if-else的dfs(i，n)函数**
3. **if(i > n) 输出正解**
4. **else中包含for循环，目的是让每个灯都亮一次**
5. **for{亮灯；if（符合条件）dfs；灭灯；}**
6. 条件：hour<=11; min<=59; 0~9小时的表示前缀没有0
7. 条件：0~9分钟的表示前缀有0，10~59没有0，用“%.2d”解决，“%02d”也可以
8. 隐含条件：不重复

```
for(int pos=0; pos<=9; ++pos)//按序亮灯
for(int j=0;j<=9;++j)        //找到上一次递归中的pos，避免重复
    if(time[j]==1)
        max=j;
if(pos>max)
```



### 代码

```cpp
class Solution
{
public:
    vector<string> res;
    vector<string> readBinaryWatch(int num)
    {
        vector<int> time(10);
        dfs(0,num,time);
        return res;
    }

    void dfs(int count,int num,vector<int> time)
    {
        if(count>=num)
        {
            int hour=1*time[0]+2*time[1]+4*time[2]+8*time[3];
            int min=1*time[4]+2*time[5]+4*time[6]+8*time[7]+16*time[8]+32*time[9];

            if(hour<=11 && min<=59)
            {
                char buffer[6];
                sprintf(buffer,"%d:%.2d",hour,min);
                                                   //想在这里判断buffer与res的元素是否重复，无法解决DS匹配问题
                res.push_back(buffer);
            }
            return;
        }
        else
        {
            int max=-1;                    //改为这里操作，让其按序，不重复
            for(int j=0;j<=9;++j)
            {
                if(time[j]==1)
                {
                    max=j;
                }
            }
            for(int pos=0; pos<=9; ++pos) 
            {
                time[pos]++;
                if(pos>max)             
                {
                    dfs(count+1,num,time);
                }
                time[pos]--;
            }
        }
    }


};
```