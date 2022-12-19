### 解题思路
给大家一个公式应该就能明白了：f(n)=f(n-1)+f(n-2)+f(n-3)

### 代码

```cpp
class Solution {
public:
    int waysToStep(int n) {
        if(n<3)
        {
            return n;
        }
      long  int first=1,second=2,third=4;
        long int temp;
        while(n>3)
        {
            temp=third;
          third=(third+second+first)%1000000007;
          first=second;
          second=temp;
          n--;
        }
        return third;
    }
};
```