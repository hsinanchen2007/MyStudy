### 解题思路
首先要理解题目的意思，给你一串有效匹配的括号，将这些括号成对分为两组，一组用0表示，一组用1表示。但是不是任意分组，我们需要保证这两组中的括号深度最小。读懂题目后就不难啦，首先看两种情况。情况一，“（）”，这是深度为1的括号对，分给哪一组都无所谓；情况二，“(((())))”，这是福嵌套的括号对，深度为4，要怎么样才能两组的深度都最小呢？那就是逐层抽取，第一层为a组，第二层为b组，第三层为a组，第四层为b组，这样的answer={0,1,0,1,1,0,1,0}，每组的深度都是2。看完两种情况后就可以处理“（）（（（）））（）（）”这样的啦。

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> answer;
        int i=0;            
        int flag=0;
        while(i<seq.size())
        {
            if(seq[i]=='(')
            {
                int val=flag%2;
                answer.push_back(val);
                flag++;
            }
            if(seq[i]==')')
            {
                flag--;
                int val=flag%2;
                answer.push_back(val);
            }
            i++;
        }
        return answer;
    }
};
```