### 解题思路
DP算法
1、最优子结构
    数组第i个表示以i结尾的所有序列和的最值。比如【4,5,6,7,8】：
    nums[3] 有两种情况，4->6，5->7，分别为 Nums[1] 和 nums[0] 的最值加上本身
    nums[4] 也是如此 nums[2]->8、nums[1]->8，分别为nums[2] 和 nums[1] 的最值加上本身
    以此类推
2、重复子问题
    由上面可以看出，每一个i 节点的最值都是由隔一层的上两层所决定，即 nums[i] 取决于 nums[i-2] 以及 nums[i-3]。
3、状态方程
    max_money[i] = max(max_money[i-3]，max_money[i-2]) + nums[i]。

最后在末尾两个位置有最值。

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size <= 0){
            return 0;
        }else if(size == 1){
            return nums[0];
        }else if(size == 2){
            return max(nums[0],nums[1]);
        }

        int* max_money = new int[size];
        max_money[0] = nums[0];
        max_money[1] = nums[1];
        max_money[2] = nums[0] + nums[2];
        for(int i=3;i<size;++i){
            int max = max_money[i-2] > max_money[i-3] ? max_money[i-2] : max_money[i-3];
            max_money[i] = max + nums[i];
        }
        return max(max_money[size-1],max_money[size-2]);
    }
};
```