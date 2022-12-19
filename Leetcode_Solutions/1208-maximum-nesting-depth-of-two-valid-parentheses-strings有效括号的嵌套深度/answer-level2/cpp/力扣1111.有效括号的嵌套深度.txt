### 解题思路
![image.png](https://pic.leetcode-cn.com/4028752d52c5fc36c9f3b15f438f28216dd9a90617a931dc121c713797990e39-image.png)




这道题其实实现起来并不难，关键是要理解题意。其实我也理解了题意，但是没有想到合适的方法。
首先，将题目总结下：
1.字符串一定是有效的，意味着字符串是成双成对的（这个我想到了）
2.需要分成不相交的有效括号字符。这个不相交我迷惑了一下，开始是以为只能是如[0,0,1,1,1,1]这样的，就是说A在一边，B在另外一边，但是看例子显然不是这样。
3.要求字符串的深度最小。

第3个要求我开始根本没考虑，我考虑的是这道题的考点。要求分为A,B两个有效括号，那么就应该是一个入栈出栈的问题，保证配对就可以了。
因此，本题的难点是如何将配对和深度同时考虑。

深度最小的含义是什么？观察深度的定义方法，是嵌套的层数。也即是需要将嵌套的层数变的最小。然后看输出知道A和B可以离散地分布在任何地方（保证有效性即可），如果让A和B的层数一直保持着较低的层数，那么最好的方式就是两个深度几乎保持一致，因为深度总是那么深，如果AB深度接近，总体深度就比较低了。

那么可以有这样的思路

对应的代码如下：

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int deepa=1;
        int deepb=0;
        vector<int> vec(seq.size(),1);
        for(int i=1;i<seq.size();i++)
        {
            if(seq[i]=='(')
            {
                if(deepa>deepb){vec[i]=0;deepb++;}
                else{deepa++;}
            }else
            {
                if(deepa<deepb){vec[i]=0;deepb--;}
                else{deepa--;}
            }
        }
    return vec;}
};
```
这也是最原始的思路的实现。这样的代码和清晰，但是这里定义了两个深度的变量。于是，思考一下可不可以只用一个深度来解决这个问题。题中说了答案并不唯一，即我们所求答案是所有答案的一个子集。我们可以这样规定，只要是奇数的加深度的动作，都置为A，只要是奇数的减去深度的动作我们都置为B；只要是偶数的加深度的动作，都置为B，只要是偶数的减去深度的动作都置为A。
在这样的思路下，可以写出最终的解。
再次强调，我们的答案是所有答案的一个子集。
### 最终代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int deep=0;
        vector<int> vec;
        for(auto ch:seq)
        {
            if(ch=='(')
            {deep++;
                if(deep%2)vec.push_back(1);
                else
                vec.push_back(0);
            }
            else{
                deep--;
                if(deep%2)vec.push_back(0);
                else vec.push_back(1);
            }
        }
    return vec;}
};
```