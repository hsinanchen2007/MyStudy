### 解题思路
其实就是数字电路里的有限状态机

### 代码

```cpp
class Solution {
public:
    int fsm(int k) {
        switch(k) {
            case 0: 
                return 1;
                break;
            case 1: 
                return 2;
                break;
            case 2: 
                return 0;
                break;
            default: return -1;
        }
    }
    int singleNumber(vector<int>& nums) {
        int re = 0;
        int cnt = 0;
        for (int i=0; i<32; i++) {
            cnt = 0;            
            for (int j=0; j<nums.size(); j++) {
                if (nums[j]>>i & 1 == 1) {
                    cnt = fsm(cnt);
                }
            }
            if (cnt == 1) re |= (1<<i);
        }
        return re;
    }
};
```