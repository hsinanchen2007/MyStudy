### 解题思路
第一步： 先求出所有异或值s，相当于求出返回值两个数之间的异或值
第二步：做一个lowbit操作（s & -s）获得最后一个1的位置（而这个1肯定属于两个数不同位的那一个1），（其实随便找到哪一个位置的1都是可以的）
第三步：利用这个1把数组所有数分成两组（对应两个数）分别重新异或（相当于重新做136）
第四部：获得最终过滤的值

### 代码

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int s = 0;
        for (int num : nums) {  // 第一步
            s ^= num;
        }
        
        int k = s & (-s);  // 第二步 lowbit操作
        
        vector<int> ret(2);
        
        for (int num : nums) {  // 第三 第四步
            if (num & k) {
                ret[0] ^= num;
            } else {
                ret[1] ^= num;
            }
        }
        
        return ret;
    }
};
```