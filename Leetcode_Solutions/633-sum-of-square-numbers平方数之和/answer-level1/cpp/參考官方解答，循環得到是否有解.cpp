### 解题思路
枚舉所有可能解法，判斷每一個減去當前值的余數是否是一個平方數，如果是則返回true，如果沒有找到則返回false

### 代码

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0) return true;
        long j=0,res=0,sq=0;
         for(int i=1;j<c;i++)
        {
            j=pow(i,2);
            res=c-j;
            if(res<0) return false;
            sq=sqrt(res);
            if(pow(sq,2)==res) return true;
        }
        return false;
    }
};
```