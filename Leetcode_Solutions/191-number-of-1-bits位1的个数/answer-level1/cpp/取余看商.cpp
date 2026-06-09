执行用时 :4 ms, 在所有 C++ 提交中击败了85.44%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了8.89%的用户

```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        
        while(n>0){
            
            if(n%2 == 1)//如果是十进制字符串则应除以10
                count++;
            
            n = n/2;
        }
        
        return count;
    }
};
```
