解释直接搬运评论中某位仁兄的留言，核心思想是异或运算的交换律：

```
a ^ b ^ c <=> a ^ c ^ b

任何数于0异或为任何数 0 ^ n => n

相同的数异或为0: n ^ n => 0

var a = [2,3,2,4,4]

2 ^ 3 ^ 2 ^ 4 ^ 4等价于 2 ^ 2 ^ 4 ^ 4 ^ 3 => 0 ^ 0 ^3 => 3
```



```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int temp=0;
        
        for(int i=0; i<nums.size(); i++){
            
            temp = temp ^ nums[i];//遍历数组，从首位开始连续进行xor运算，最终可以得到不同的那个数
        }
        
        return temp;
    }
};
```
