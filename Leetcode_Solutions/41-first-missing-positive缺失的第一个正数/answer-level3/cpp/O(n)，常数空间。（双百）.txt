### 解题思路
设置一个tail初始为nums.size() - 1，**tail表示最后一个有效元素，tail右边的元素都是无效的**

**有效的定义：不在区间[1, tail + 1]的数**

## 先遍历一遍，
if (nums[i]不合法){
    swap(nums[i], nums[tail]);
    tail--;
}
这一波保证了目前1~tail这个区间都是合法的。

## 把每个数a[i]放到a[i] - 1的位置，如果重复(a[i] - 1这个位置已经用有了)，则放到不合法区。如果大于tail + 1，也放到不合法区。

### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int tail = nums.size() - 1;
        while (tail >= 0 && (nums[tail] <= 0 || nums[tail] > tail + 1)){
            tail--;
        }
        for (int i = 0; i <= tail ; i++){
            if (nums[i] <= 0 || nums[i] > tail + 1){
                swap(nums[i], nums[tail]);
            }
            while (tail >= 0 && (nums[tail] <= 0 || nums[tail] > tail + 1)){
                tail--;
            }
        }

        for (int i = 0; i <= tail; i++){
            if (nums[i] == i + 1){
                continue;
            }
            while (nums[i] != i + 1 && i <= tail){
                int want = nums[i] - 1;
                if (nums[want] == want + 1 || nums[i] > tail + 1){
                    swap(nums[i], nums[tail]);
                    tail--;
                    continue;
                }
                swap(nums[i], nums[want]);
            }
        }
        return tail + 2;
    }
};
```