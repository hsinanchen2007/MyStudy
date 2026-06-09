### 解题思路
核心思路：是否接受第n个预约取决于前n-1的接受情况与第n个预约的时长
动态规划：
（1）若不接受第n个预约，预约最长总时长=max（接受第n-1个预约的总时长，不接受第n-1个预约的总时长）
（2）若接受第n个预约，预约最长总时长=不接受第n-1个预约的总时长+第n个预约所需时长
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :9.6 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int nac=0;
        int acc=nums[0];
        for(int i=1;i<nums.size();i++){
            int nac2=max(nac,acc);
            int acc2=nac+nums[i];
            nac=nac2;
            acc=acc2;
        }
        return max(nac,acc);
    }
};
```