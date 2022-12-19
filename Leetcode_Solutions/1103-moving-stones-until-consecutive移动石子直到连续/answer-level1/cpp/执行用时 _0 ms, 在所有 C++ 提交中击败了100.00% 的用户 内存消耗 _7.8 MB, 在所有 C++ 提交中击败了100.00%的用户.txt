### 解题思路
此处撰写解题思路
max为三个数（排序后）的两两之间的空隙，min分别有0,1,2三种情况，0为连续的，1为两两空隙为1的，其余的就是2的情况了，画图更好分析，我感觉代码可以更简洁吧
### 代码

```cpp
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
         vector<int> v;
      vector<int> target;
target.push_back(a);
    target.push_back(b);
    target.push_back(c);
    sort(target.begin(),target.end());
int x=target[1]-target[0]-1;
int y=target[2]-target[1]-1;   

int max=x+y;
    int min=0;
if(x==0 && y==0)
    min=0;
else
{
    if(x>1 && y>1)
        min=2;
    else
        min=1;
}
v.push_back(min);
v.push_back(max);
    return  v;
   }
    
};
```