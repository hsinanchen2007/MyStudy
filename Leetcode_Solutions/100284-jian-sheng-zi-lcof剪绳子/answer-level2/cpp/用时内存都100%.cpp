### 解题思路
此处撰写解题思路
1.只要凑3就完事了
### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        if(n%3==0)return pow(3,n/3);
        if(n%3==1)return pow(3,n/3 -1)*4;
        else return pow(3,n/3)*2;

    }
};
```