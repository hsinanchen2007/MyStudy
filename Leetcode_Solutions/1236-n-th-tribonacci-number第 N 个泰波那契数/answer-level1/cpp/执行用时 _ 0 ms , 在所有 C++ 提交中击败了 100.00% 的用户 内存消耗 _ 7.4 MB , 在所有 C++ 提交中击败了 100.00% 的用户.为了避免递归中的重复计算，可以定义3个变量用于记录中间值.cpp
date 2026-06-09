### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int tribonacci(int n) {
    if(n==0)
        return 0;
    if(n==1||n==2)
         return 1;
    int a1=0;
    int a2=1;
    int a3=1;
    int i=3;
    int a4;
    while(i<=n)
        {a4=a1+a2+a3;
        a1=a2;
        a2=a3;
        a3=a4;
        i++;
        }
        return a4;
    }
    

};
```