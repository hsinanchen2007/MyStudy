### 解题思路
注意：
    取余操作要放在前面

### 代码

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product=1, sum=0;
        int yushu;
        if (n<=0) return -1;
        while (n){
            yushu=n%10; //一定要放在前面
            n=n/10;
            product*=yushu;
            sum+=yushu;
        }
        return product-sum;
    }
};
```