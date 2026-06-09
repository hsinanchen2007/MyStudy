### 解题思路
关键是要避免删除重复数组
避免对数据的多次移动
- 定义双指针，头尾指针
- 头指针指示当前元素，尾指针指示判断元素
- 当尾指针第一次移动到不相等的时候
- 将尾指针所指示的数据插入到头指针的下一个位置

### 代码
**24ms版本 被57%老哥打败**
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 重复数据避免多次删除
        if(nums.size() < 1) return 0;
        int head_cur = 0; // 指向当前判断数据
        int tail_cur = 1; // 指向下一个不重复数据
        while(tail_cur < nums.size()){
            while(tail_cur < nums.size() && nums[head_cur] == nums[tail_cur]) ++tail_cur;
            if(tail_cur < nums.size()) nums[++head_cur] = nums[tail_cur++];
            else break;
        }
        return head_cur + 1;
    }
};
```
- 可以在循环里直接判断是否越界

**16ms版本**
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 重复数据避免多次删除
        if(nums.size() < 1) return 0;
        int head_cur = 0; // 指向当前判断数据
        int tail_cur = 1; // 指向下一个不重复数据
        while(tail_cur < nums.size()){
            while(nums[head_cur] == nums[tail_cur]) {
                ++tail_cur;
                if(tail_cur == nums.size()) return head_cur + 1;
            }
            nums[++head_cur] = nums[tail_cur++];
        }
        return head_cur + 1;
        // 多次判断是否越界
    }
};
```
- 多次重复判断是否越界

**8ms版本 -打败百分之99的老哥**
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 重复数据避免多次删除
        if(nums.size() < 1) return 0;
        int head_cur = 0; // 指向当前判断数据
        int tail_cur = 1; // 指向下一个不重复数据
        nums.push_back(nums[0] - 1); // 哨兵
        while(tail_cur < nums.size()){
            while(nums[head_cur] == nums[tail_cur]) {
                ++tail_cur;
            }
            nums[++head_cur] = nums[tail_cur++];
        }
        return head_cur;
        // 多次判断是否越界
    }
};
```
- 增设哨兵，当判断到哨兵时候由于元素唯一，加入后，直接导致外层循环退出。


**不使用哨兵，将循环里的while改成if判断即官方给的4ms版本但是我跑出来是12ms**
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 重复数据避免多次删除
        if(nums.empty()) return 0;
        int head_cur = 0; // 指向当前判断数据
        int tail_cur = 1; // 指向下一个不重复数据
        while(tail_cur < nums.size()){
            if(nums[tail_cur] != nums[head_cur]) nums[++head_cur] = nums[tail_cur];
            tail_cur++;
        }
        return head_cur + 1;
    }
};
```
有老哥知道为什么吗
