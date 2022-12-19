### 解题思路

### 代码

```cpp
class Solution 
{
public:
    #define re(x) x? 0:1 
    
    int kthGrammar(int N,int K)
    {
        if(N==1) return 0;

        if(K%2)
            return kthGrammar(N-1,K/2+1);
        else return re(kthGrammar(N-1,K/2));
    }
};
```
![image.png](https://pic.leetcode-cn.com/548bf99ff417a933f11a5cc83705fef7066afa559dd8b2f445f843115e898e57-image.png)
