### 解题思路
此处撰写解题思路
a[0]分子  a[1]分母 


### 代码
```cpp
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int a[2] = {0,0};
        int nsize = cont.size();
        a[0] = cont[nsize-1];
        a[1] = 1;
        int temp =0;
        for(int i = nsize - 2; i>=0;i--)
        {
            temp = a[1];
            a[1] = a[0];
            a[0] = cont[i]*a[0]+temp;
        }

        return {a[0],a[1]};
        
    }
};
```