### 解题思路
此处撰写解题思路
简单遍历，用变量abc分别表示手中各个钞票的个数
如果收到5刀，a++没什么好说的
如果收到10刀，只能用5刀钞票去找零，a--，小于零出错
如果收到20刀，优先找一个10加一个五，其次才找三张5，哪个小于零都不行，遍历完无毛病就能返回true了
### 代码

```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a=0,b=0,c=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            a++;
            else if(bills[i]==10)
            {
                b++;
                a--;
                if(a<0)
                return false;
            }
            else{
                c++;
                if(b>0)
                {
                    b--;
                    a--;
                    if(a<0 || b<0)
                     return false;
                }
                else{
                    a=a-3;
                    if(a<0)
                    return false;
                }
            }
        }
        return true;
    }
};
```