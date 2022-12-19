### 解题思路
初始化第一个区域为`[1, nums[0]]`,
然后每次从区域`[left, right]`内找出可以跳到的最远地点的那一个，最远地点记为maxdis
再更新区域为`[right + 1, maxdis]`
重复直到超出最大的距离，得到跳数

### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) { //不用跳
            return 0;
        }
        if (nums[0] >= nums.size() - 1) {   //加这个比较快
            return 1;
        }
        //选择区域
        int left = 1;   
        int right = nums[0];

        int jump = 1;   //上面那个区域相当于在第一格处跳了一下，jump等于1
        
        while (right < nums.size() - 1) {//区域超出
            int maxdis = right; 
            //找到[left, right]中跳得最远的那一个
            for (int i = left; i <= right; i++) {
                if (i + nums[i] > maxdis) {
                    maxdis = i + nums[i];
                }
            }
            //下一个区域为[right + 1, maxdis]
            left = right + 1;
            right = maxdis;
            jump++;
        }
        return jump;
    }
};
```