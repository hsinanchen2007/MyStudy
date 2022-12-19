具体[见此](https://newdee.gitbook.io/leetcode/leetcode-index/191.number_of_1_bits)  

```
class Solution {
public:
    int hammingWeight(uint32_t n) {
       uint32_t temp=10000000000000000000000000000000;
        int res=0;
        while(temp)
        {
            if(n & temp) res++;
            temp=temp>>1;
        }
       
      
        return res;
    }
};
```

> 执行用时 : 4 ms, 在Number of 1 Bits的C++提交中击败了98.81% 的用户  
内存消耗 : 8.3 MB, 在Number of 1 Bits的C++提交中击败了5.21% 的用户