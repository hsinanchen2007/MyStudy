### 解题思路
执行结果：通过  显示详情
执行用时 :16 ms, 在所有 C++ 提交中击败了98.68%的用户
内存消耗 :11.9 MB, 在所有 C++ 提交中击败了66.98%的用户

从左到右遍历一遍字符串，分一下几种情况（记下第一个LR的位置，然后在下一个字符型LR的时候处理这一段的字符）
L-----L   里面‘.’全部填充L；
L-----R   里面左边一半填充L，右边一半填充R（注意这里要分类，中间可能会有一个‘.’或者没有）
R-----R   里面‘.’全部填充R；
R-----L   不用处理；

### 代码

```cpp
class Solution {
public:
    //从a-b位置的全部变成指定的lr符号
    void trans(string& temp,int a,int b,char lr)
    {
        if(a<=b)
        {
            for(int i=a;i<=b;i++)
            {
                temp[i]=lr;
            }
        }
    }
    string pushDominoes(string dominoes) {
        string temp=dominoes;//用于存储结果
        char temp1='N';//上一个识别的字符是L还是R
        int index=-1;//上一个识别的字符是位置标号
        for(int i=0;i<dominoes.size();i++)
        {
            //判断此时的字符串是L
            if(dominoes[i]=='L')
            {
                //左侧符号位为N的时候，左侧全部填充L
                 if(temp1=='N')
                 {
                     trans(temp,0,i-1,'L');
                 }
                //左侧符号位为L的时候，左侧全部填充L
                 else if(temp1=='L')
                 {
                     trans(temp,index+1,i-1,'L');
                 }
                //左侧符号位为R的时候，靠近左侧填充R，右侧填充L（填充个数为m=(i-index-1)/2）
                 else 
                 {
                     int m=(i-index-1)/2;
                     trans(temp,index+1,index+m,'R');
                     trans(temp,i-m,i-1,'L');
                 }
                 temp1='L';
                 index=i;
            }
            //此时的符号位R
            else if(dominoes[i]=='R')
            {
                //上一个符号为R,则填充R，其他情况不用考虑
                if(temp1=='R')
                {
                    if(i-1>=index+1)
                        trans(temp,index+1,i-1,'R');
                }
                 temp1='R';
                 index=i;  
            }
        }
        //左侧是R到字符串结尾没有处理 需要全部变成R
        if(temp1=='R')
            trans(temp,index+1,temp.size()-1,'R');
        return temp;
    }
};
```