### 解题思路
核心思路：当n%2==1时，1个数计数器+1，然后n减半
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :5.8 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum=0;
        while(n!=0){
            if(n%2==1)sum++;
            n=n/2;
        }
        return sum;
    }
};
```