### 解题思路
第一个指针从0开始递增，第二个指针从int(根号c)开始递减,直到满足条件或者第一个指针超过第二个指针导致退出循环。
注意：因为测试数据中有较大的数，因此应使用long int类型。

### 代码

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        long int l=0, r=sqrt(c), temp_sum=0;
        while(l <= r) {
            temp_sum = l*l + r*r;
            if(temp_sum == c) return true;
            else if(temp_sum < c) l++;
            else r--;
        }
        return false;
    }
};
```