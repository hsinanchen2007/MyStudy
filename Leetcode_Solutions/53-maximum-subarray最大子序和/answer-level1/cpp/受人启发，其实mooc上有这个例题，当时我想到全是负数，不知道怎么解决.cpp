### 解题思路
其实感觉动态规划这种方式，已经有朋友解释得蛮清楚了（应该在题解第二页，我忘记了），他其实也是一层一层地迭代下去。那另一个也蛮容易的理解方式就是，一旦前面的和为负数，那就直接抛弃，他对后面的子列的求和最大值就不是增益作用了，拖后腿了。所以判断，如果sum>0，就加下去，否则，就抛弃，从头开始，设置sum为当前值。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //先考虑一下框架(1.空 2.负数 3. 正常)
        if(nums.size() == 0) return 0;

        int result = nums[0], sum = 0;
        
        for(int cur:nums){   //遍历数组，因为这种方式从第一个元素遍历起，所以还是sum初始化为0
            if(sum > 0) sum += cur;  //只有前面的和为正数才有意义加上后面的元素
            else sum = cur;          //否则就重新从当下cur这个元素开始计算求和
            result = max(result, sum);  //从第一个元素就开始比起
        }
        return result;
    }
};
//如果全是负数的话，抛弃前面的，sum = cur，并且前面的result已经经过比较。
```