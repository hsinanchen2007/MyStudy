### 方法一：两次迭代 ###
#### 思路 ####
- `tree`数组长度`16`，值全部初始化为`-1`，用来记录树中每个节点的值（虽然长度`15`就足够表示深度为`4`的树的所有节点了，但是取长度`16`使得边界条件处理起来更方便）；`times`数组长度`16`，值全部初始化为`0`，用来记录每个节点在求路径和过程中的重复累计次数（即经过该节点的路径条数）
- 第一次迭代，将`nums`中每个节点的值填入`tree`数组中对应位置
  - 节点深度`dep = num / 100`，节点位置`pos = num / 10 % 10`，节点的值`val = num % 10`
  - 节点在数组中的下标`idx = pow(2, dep - 1) - 1 + pos`
- 第二次迭代，从`tree`和`times`的右端向左端遍历，`i`从`15`开始，直到`i == 0`退出
  - 若`tree[i]`为`-1`，跳过本轮循环
  - 若`times[i]`为`0`，则当前节点及其所有祖先节点的重复次数都增加`1`
    - 当前节点的父节点下标`j = i / 2`
  - 将`times[i] * tree[i]`加入结果
#### 代码 ####
```cpp []
class Solution {
public:
    int pathSum(vector<int>& nums) {
        int tree[16], times[16]{0}, res = 0;
        fill_n(tree, 16, -1);
        for (int &num : nums) {
            int dep = num / 100, pos = num / 10 % 10;
            tree[(int)pow(2, dep - 1) - 1 + pos] = num % 10;
        }
        for (int i = 15; i; --i) {
            if (!~tree[i]) continue;
            if (!times[i]) for (int j = i; j; j /= 2) ++times[j];
            res += times[i] * tree[i];
        }
        return res;
    }
};
```
```python3 []
class Solution:
    def pathSum(self, nums: List[int]) -> int:
        tree, times, res = [-1] * 16, [0] * 16, 0
        for num in nums:
            dep, pos = num // 100, num // 10 % 10
            tree[2**(dep - 1) - 1 + pos] = num % 10
        for i in range(15, 0, -1):
            if not ~tree[i]: continue
            if not times[i]:
                j = i
                while j:
                    times[j] += 1
                    j //= 2
            res += times[i] * tree[i]
        return res
```
### 方法二：一次迭代 ###
#### 思路 ####
- 前文的方法还可以稍加改进，利用`nums`为**升序**数组的性质，只需要一次迭代即可完成任务
- 本方法中只需要长度为`16`的`times`数组
- 逆序遍历`nums`数组，按照前文的公式计算当前节点的下标
  - 将`val * max(1, times[idx])`加入结果（重复次数至少为`1`）
  - 更新父节点的重复次数，为其增加`max(1, times[idx])`（子节点的重复次数），随迭代逐层向上传递
#### 代码 ####
```cpp []
class Solution {
public:
    int pathSum(vector<int>& nums) {
        int times[16]{0}, res = 0;
        for (auto &&it = nums.rbegin(); it != nums.rend(); ++it) {
            int dep = *it / 100, pos = *it / 10 % 10;
            int idx = pow(2, dep - 1) - 1 + pos;
            res += *it % 10 * max(1, times[idx]);
            times[idx / 2] += max(1, times[idx]);
        }
        return res;
    }
};
```
```python3 []
class Solution:
    def pathSum(self, nums: List[int]) -> int:
        times, res = [0] * 16, 0
        for num in nums[::-1]:
            dep, pos = num // 100, num // 10 % 10
            idx = 2**(dep - 1) - 1 + pos
            res += num % 10 * max(1, times[idx])
            times[idx // 2] += max(1, times[idx])
        return res
```
