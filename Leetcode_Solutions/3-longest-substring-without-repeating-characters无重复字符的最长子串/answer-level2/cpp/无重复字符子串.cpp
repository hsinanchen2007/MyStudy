### 解题思路
时间有点长，下次改进。。。。
思路：先记录字符串的长度，然后用两个指针x，y。
y的范围是 如果从y到最后的长度如果比前面最大的长度（max值）要短的话，就停止。

每次x从y开始遍历每次如果没有与之前相同的元素就存进向量里 更新向量，再接着遍历与向量元素比较

如果遇到与向量元素相同的，就记下元素在向量里的位置，之后y就要跨过长度为那个位置（即：y要跳到那个与我扫到的元素一样且靠前面的那个元素），然后判断向量长度是否比max大，若大 代替。

然后再跳到第一步后，x再从y开始遍历

若x遍历到最后 只需要将当前向量长度与max值比较，若向量长度大，就更新max。

还未学到hash 初学者。
### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
       int j=0,n=0,x=0,size=0,ps=0,y=0,m=0,max=0;
       vector<char>s2;
       while(s[j]!='\0')                          //记录字符串长度
       {
           j++;
       } 
       while(j-y>max)                            //若从y到最后剩余的元素个数少与max
       {
           x=y;                                  //x从y开始遍历
           while(x!=j)                           //若x未到最后
           {
             for( m=0;m<n;m++)                   //当前元素与前面的已存向量比较
             {
                 if(s[x]==s2[m])                 //若有相等的跳出循环
                 break;
             }
             if(m==n)                           //判断m的值 m==n 说明没有相等的
             {s2.push_back(s[x]);               //存入向量
                 x++;}                         //下一个元素
             else
             break;                            //否则遇到相同的跳出循环 将y进行跳转
             n=s2.size();                      //更新向量长度
           }
           if(x==j)                            //如果是因为x到最后才跳出循环的话 ，看当前向量长度是否比max大
           {
               if(s2.size()>max)
              { max=s2.size();break;}
               else
               break;
           }
           else                    //否则看向量长度是否比max大 处理后 将向量清空，y跳到相同元素靠前的那个的位置上，
           {
              if(s2.size()>max)
              max=s2.size();
              s2.clear();
              n=0;
              y=y+m+1;
           }
       }
       return max;
    }
};
```