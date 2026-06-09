### 解题思路
分为三个时间段来看，分别是过去，现在和未来
过去last代表当前预约者之前的最长预约时间，现在now代表包括当前预约者的最长预约时间，未来future代表包括下一个预约者的最长预约时间，下一个预约者的预约时间为time
则有 future = max（now， time + last）
由此来递推
### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int last = 0;
        int now = 0;
        int future = 0;
        for(int num : nums)
        {
            future = max(now, last + num);
            last = now;
            now = future;
        }
        return now;
    }
};
```