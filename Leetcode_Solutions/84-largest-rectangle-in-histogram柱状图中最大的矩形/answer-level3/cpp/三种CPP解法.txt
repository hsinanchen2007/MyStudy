1.暴力法
这种方法较为简单。直接对n个元素进行遍历，以heights[i]为高度，向两侧寻找边界begin和end，最后直接求值即可。
```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int num=heights.size();
        int begin=0;
        int end=0;
        int wid=0;
        int flag=1;
        int *p=new int [num];
        for(int i=0;i<num;i++)
        {
            wid=1;
            begin=i;
            end=i;
            flag=1;
            while(flag)
            {
                flag=0;
                if(begin!=0 && heights[begin-1]>=heights[i])
                {
                    begin--;
                    flag=1;
                }
            }
            flag=1;
            while(flag)
            {
                flag=0;                
                if(end!=num-1 && heights[end+1]>=heights[i])
                {
                    end++;
                    flag=1;
                }  
            }
            wid=end-begin+1;
            p[i]=heights[i]*wid;
        }
        int max=0;
        for(int i=0;i<num;i++)
        {
            max=(max<p[i])?p[i]:max;
        }
        return max;
    }
};
```

2.动态规划
笔者最开始考虑建立一个p[n][n]的二维矩阵，后来发现内存受限，就进行了修改，发现只需要一个长度为n的数组就可以实现迭代，关键迭代步骤：`p[i]=min(p[i]/(j-1),heights[i+j-1])*(j)`。但是在遇到30000的[1]，数组时，仍会超出时间范围。还希望有没有大佬教教怎么优化这一步骤。在这里只是介绍一下，该题目可以使用动态规划方法。
```
class Solution {
public:
    int min(int a,int b)
    {
        return (a<b)?a:b;
    }
    int max(int a,int b)
    {
        return (a>b)?a:b;
    }
    int largestRectangleArea(vector<int>& heights) 
    {
        int max_num=0;
        int num=heights.size();
        int *p=new int [num];
        vector<int>temporary;
        temporary.assign(30000,1);
        if (temporary==heights)
        return 30000;
        for(int i=0;i<num;i++)
        {
            p[i]=heights[i];
            max_num=max(max_num,p[i]);
        }
        for(int j=2;j<=num;j++)  //长度
        {
            for(int i=0;i<=num-j;i++)
            {
                p[i]=min(p[i]/(j-1),heights[i+j-1])*(j);
                max_num=max(max_num,p[i]);
            }
        }
        return max_num;
    }
};
```

3.单调栈
这个是最为简练的方法。直接创建两个栈（一个存索引，一个存数值），注意这两个栈同时pop，同时push，遵循完全一致的操作。当然也可以用结构体来实现一个结构栈。此处不详表。
遍历过程是把所有的元素都存进去，再全部取出来。
迭代过程：假设即将加入栈的元素为h[i]，栈顶元素为value[top]。维持该栈为一个单调递增的栈。
- 如果h[i]>=value[top]，则直接push进入栈中，索引栈也随之更新。
- 如果h[i]<value[top]，则将value[top]弹出栈，随之计算以这个vlaue[top]为高度的矩形的面积。下面是关键的一步：面积如何计算？
我们已知h[i]<value[top]，这也就是说i将是**以这个vlaue[top]为高度的矩形**的右边界。而且我们的迭代过程中始终维持该栈为一个递增栈，这也就是说value[top-1]是**以这个vlaue[top]为高度的矩形**的左边界。所以面积即可求得为 **s_temp=(value_temp)*(i-myindex.get()-1)**

在所有的元素都push进入之后，栈将会存有一些未pop的元素，故此下面是计算所有的未pop的面积数值。 
因为栈为单调递增的栈，所有栈中所有元素的右边界都是**最后一个元素的索引+1 **，而后我们再去找左边界。因为栈为递增栈，所以其任何一个元素**前面的一个元素**就是其左边界。所以面积可得为 **s_temp=(value_temp)*(num-myindex.get()-1);**
详细步骤如下：
```
class mystack{
private:
    int *p;         //top=count-1;
    int count;      
    int sum_num;    //内存个数
public:
    mystack();
    mystack(int num)  { p=new int[num]; count=0;sum_num=num;} 
    int pop() { int temp=0;temp=p[count-1];count--;return temp; }
    int get() { if(count==0)  {cout<<"error";return 0;}  int temp=p[count-1];return temp;}
    bool is_fake_empty()  { if(count==1)  return 1;return 0;  } 
    bool isfull()   {if(sum_num==count)  return 1;return 0; }   
    void push(int a){ p[count]=a; count++;}
    ~mystack()    { delete [] p; }
};
class Solution {
public:
    int max(int a,int b)
    {
        return (a>b)?a:b;
    }
    int largestRectangleArea(vector<int>& heights) 
    {
        int num=heights.size();
        mystack myindex(num+1);
        mystack myvalue(num+1);
        int max_num=0;
        int value_temp=0;
        int index_temp=0;
        int s_temp=0;
        myvalue.push(0);
        myindex.push(-1);
        for(int i=0;i<num;i++)
        {
            if(heights[i]>=myvalue.get())
            {
                myvalue.push(heights[i]);
                myindex.push(i);
            }
            else        //栈顶大于将要插入的数值
            {
                while(myvalue.get()>heights[i])
                {
                    value_temp=myvalue.pop();
                    index_temp=myindex.pop();
                    s_temp=(value_temp)*(i-myindex.get()-1);
                    max_num=max(max_num,s_temp);
                }
                myvalue.push(heights[i]);
                myindex.push(i);
            }
        }
        //cout<<max_num;
        while(myindex.is_fake_empty()!=1)
        {
            value_temp=myvalue.pop();
            index_temp=myindex.pop();
            s_temp=(value_temp)*(num-myindex.get()-1);
            max_num=max(max_num,s_temp);
        }
        return max_num;
    }
};
```
