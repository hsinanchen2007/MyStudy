### 解题思路
1. 位运算解法, 出现三次的低位和必然为3的倍数, 计算所有数字的低位和, 对3取`mod`即是single number的低位, 在通过左移恢复即可, `n<<b`.
2. 状态机

### 代码
**位运算**
```c++ []
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 位运算求解
        int res = 0;
        for(int b=0; b<32; ++b){
            int cnt = 0;
            for(int i=0; i<nums.size(); ++i){
                cnt += (nums[i]>>b) & 0x01;
            }
            res += cnt%3<<b;
        }
        return res;
    }
};
```
```java []
class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        for(int b=0; b<32; ++b){
            int cnt = 0;
            for(int d: nums){
                cnt += (d>>b)&0x01;
            }
            res += (cnt%3)<<b;
        }
        return res;
    }
    
}
```
**自动机**
```c++ []
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 状态机
        // 初始 0 0
        // 1个1: 1 0
        // 2个1: 0 1
        // 3个1: 0 0
        // 如果是3次自动机 状态为(0, 0)->(1, 0)->(0, 1)->(0, 0) 回归初始状态
        // 如果是1次自动机 状态为(0, 0)->(1, 0) Ones中记录了只出现一次的数据
        int Ones=0;   
        int Twos=0;
        for(auto &n : nums){
            Ones = (Ones ^ n) & ~Twos;
            Twos = (Twos ^ n) & ~Ones;
        }
        return Ones;
    }
};
```