### 解题思路
这道题只要跳到大于等于终点的位置就可以了，所以每次我们都寻找在下一步能让我们跳得最远的点。

### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0;
        int step = 0;
        if (nums.size()==1) return 0;
        while (true) {
            int temp = i+1;
            for (int j=i+1; j<=nums[i]+i; j++) {
                //思考了一段时间，说实话把return放在循环里再有个++导致额外考虑size=1的情况，
                //不是很优雅，还是要多看看别人的写法
                if (j==nums.size()-1) return ++step;
                //注意，我们这里选择的是能让我们绝对距离跳得最远的点，而非相对最远的点
                temp =nums[temp]+temp > nums[j]+j ? temp : j;
            }
            i = temp;
            step++;
        }
        return -1;
    }
};
```