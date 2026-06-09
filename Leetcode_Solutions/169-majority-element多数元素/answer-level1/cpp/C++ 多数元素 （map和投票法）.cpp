## 1. 使用map记录出现过的元素以及出现次数

时间复杂度为O(n)，空间复杂度为O(n)

代码：

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(int elem : nums){
            if(m.find(elem) == end(m)){
                m.insert(pair<int,int>(elem, 1));
            }else{
                m[elem] += 1;
            }
            // 检查是否超过一半
            if(m[elem] > nums.size()/2){
                return elem;
            }
        }
    }
};
```

## 2. 投票法

+ `cand_num` 为当前候选出现最多的元素，`count`为出现次数；
+ 初始时，`cand_num = nums[0], count = 1`；
+ 开始遍历数组，如果`nums[i] == cand_num`，则`count +=1 `；否则`count -=1 `；
+ 当 `count == 0`的时候更换cand_num，继续遍历，最后的cand_num则为出现超过一半的元素

代码：

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand_num = nums[0], count = 1;
        for(int i = 1; i<nums.size(); ++i){
            if(nums[i] == cand_num) ++count;
            else{
                if(--count == 0){
                    cand_num = nums[i];
                    ++count;
                }
            }
        }
        return cand_num;
    }
};
```