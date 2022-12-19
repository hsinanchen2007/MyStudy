### 解题思路
思路同两部问题，注意溢出。

### 代码

```cpp
class Solution {
public:
    int waysToStep(int n) {
        int a1=1;int a2=2;int a3=4;int temp;
        int mode=1000000007;
        if (n==1) return 1;
        if (n==2) return 2;
        if (n==3) return 4;
        for (int i=4;i<=n;i++){
            temp=((a1+a2)%mode+a3)%mode;
            a1=a2;a2=a3;
            a3=temp;
        }
        return temp;
    }
};
```