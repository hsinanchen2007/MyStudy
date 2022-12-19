### 解题思路
建立一个hash表，然后遍历数组nums，如果nums[i]在hash表中说明是重复元素，那么返回该元素。如果不在hash表中，那么把该元素添加到hash表中。

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len = nums.size();
        map<int, bool> hash;    // 定义一个哈希表
        int result = 0;

        for(int i = 0; i < len; ++i){
            if(hash[nums[i]] == true){
                // 如果元素存在hash表中
                // return nums[i];
                result = nums[i];
            }
            else{
                // 将该元素添加到hash表中
                hash[nums[i]] = true;
            }
        }

        return result;
    }
};
```

### 解题思路
参考《剑指offer》

当扫描到第i个元素时，先检查第i个元素是不是等于i，即`nums[i] ?= i`。

- 如果不相等，那么交换当前值nums[i]和以当前值nums[i]为索引的值nums[nums[i]],如果相等说明nums[i]在i位置出现，并且又在nums[i]位置出现，便找到了一个重复值。
- 如果相等，那么继续检查下一个元素


### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len = nums.size();
        int result = 0;
        for(int i = 0; i < len; ++i){
            while(nums[i] != i){// 如果当前值和索引值不相等，说明该值不应该在这个位置

                if(nums[i] == nums[nums[i]]){
                    // 如果以当前值为索引，得到的值等于当前值，说明在另一个位置也有这个值，即有重复值
                    // 说明nums[i]在i位置出现，并且又在nums[i]位置出现
                    return nums[i];
                    result = nums[i];
                    
                }
                // 如果没有重复值则交换当前位置的值nums[i]和以当前位置值为索引的位置nums[nums[i]
                // 目的是使当前位置的值和当前索引值相等。这样便于检查有没有重复值
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }

        return result;
    }
};