### 解题思路
此处撰写解题思路
通过观察可发现，在遍历分割时是应该分到a还是b的参照应该是两边左括号的个数。
若a的左括号个数＜=b，则判定a的左括号增加优先级更高，在碰到左括号时将其割给a，反之给b。
若a的左括号个数>b，则判定a的右括号增加优先级更高，在碰到右括号时将其割给a，反之给b。
通过判定左括号数量保证了嵌套层数相差最小
右括号则用于保证嵌套成功
### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int _size=seq.size();
        int Lcount1=0,Lcount2=0;
        vector<int> k;
        for(int i=0;i<_size;i++)
        {
            if(seq[i]=='(')
            {
                if(Lcount1<=Lcount2)
                {
                    Lcount1++;
                    k.push_back(0);
                }
                else
                {
                    Lcount2++;
                    k.push_back(1);
                }
            }
            if(seq[i]==')')
            {
                if(Lcount1>Lcount2)
                {
                    Lcount1--;
                    k.push_back(0);
                }
                else
                {
                    Lcount2--;
                    k.push_back(1);
                }
            }
        }
        return k;
    }
};
```