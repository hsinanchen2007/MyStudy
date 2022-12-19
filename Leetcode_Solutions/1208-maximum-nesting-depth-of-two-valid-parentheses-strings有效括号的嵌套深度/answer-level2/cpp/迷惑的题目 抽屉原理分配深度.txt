# 题目分析
#### 1. 题目要我们干什么？
划分一个括号串成两个串A,B，使最大深度```maxdepth（depthA,depthB）```最小
#### 2. 划分是什么意思呢？
例如 "( ( ( ) ) ) " 可以划分为"**(** *(* **( )** *)* **)**" 粗体斜体分别代表A B 部分。
实际上就是原串有一些**括号对**，把一些 **括号对** 划分给A，一些给B。
#### 3. 限制条件：不能相交
没搞懂这什么意思还是A了，至少A包含B，B又包含A的来回嵌套的可以的。
可能是指不能" **(** *(*  **)** *)* "这样吧...
#### 4. 限制条件：max深度最小
就是抽屉原理嘛...要让max最小，即按抽屉原理，把深度平均分给A，B就好了。
例如："**(** *(* **( )** *)* **)**" 0层深度括号（最外层）给A，1层（嵌套了一次）给B，2层深度给A，这样A深度2，B深度1，最大深度2，此时最大深度最小。

# 题解代码
```
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) 
    {   
        //不懂相交的定义 抽屉原理分配深度
        int count=1;//count深度计数器
        int flag;//划分A B的赋值
        vector<int> result(seq.size());
        if(seq.size()==0)
            return result;
        stack<int> s;//栈保留左括号下标
        for(int i=0;i<seq.size();i++)
        {
            if(seq[i]=='(')//入栈左括号下标
            {
                s.push(i);
                count++;
            }
            else//出栈，找到匹配的左右括号，划分A 或 B
            {
                flag=count%2;//按奇偶划分A B，即抽屉原理，A一层，B一层
                result[s.top()]=flag;//左括号赋值
                result[i]=flag;
                
                s.pop();
                count--;//出一层嵌套记得善后计数器
            }
        }

        return result;
    }
};
```