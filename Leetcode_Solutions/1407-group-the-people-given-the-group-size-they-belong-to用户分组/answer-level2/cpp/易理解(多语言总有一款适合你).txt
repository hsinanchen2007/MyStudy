# 解题思路
思路很简单，遍历`groupSizes`，将`groupSizes[i]`所在的组标记，从`i+1`查找与`groupSizes[i]`相同的，作为一个组，并将其的组别设置为`0`(防止后面重复)

# 代码

## `CPP`
```cpp
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int len = groupSizes.size();
        vector<vector<int>> re;
        if (0 != len) {
            for (int i = 0; i < len; i++) {
                int nums = groupSizes[i];   // 获取组内成员个数
                if (0 == nums) continue;    // 跳过
                else if (1 == nums) {       // 一个独立作为一组
                    vector<int> tmp {i};
                    re.push_back(tmp);
                } else {
                    vector<int> tmp(nums);
                    tmp[--nums] = i;
                    for (int j = i + 1; j < len && nums > 0; j++) { // 根据个数向后查找组员
                        if (groupSizes[i] == groupSizes[j]) {
                            groupSizes[j] = 0;                      // 标记，防止后面重复
                            tmp[--nums] = j;
                        }
                    }
                    re.push_back(tmp);
                }
            }
        }
        return re;
    }
};
```
![image.png](https://pic.leetcode-cn.com/c67178245564d869e8ac399397f74986d35a8958e1e332c70e931daa656fe093-image.png)

## `Python`
```python
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        _len = len(groupSizes)
        re = []
        if 0 != len:
            for i in range(_len):
                need = groupSizes[i]
                if 0 == need:
                    continue
                elif 1 == need:
                    re.append([i])
                else:
                    tmp = [i] * need
                    need -= 1
                    for j in range(i+1, _len):
                        if groupSizes[i] == groupSizes[j]:
                            groupSizes[j] = 0
                            tmp[need] = j
                            need -= 1
                            if not need > 0:
                                break
                    re.append(tmp)
        return re
```
![image.png](https://pic.leetcode-cn.com/9d7ed2f094443d3944ce27bf77f745d3c472a6d02d772eec6f9b738e8a1c9c08-image.png)

## `Go`
```go
func groupThePeople(groupSizes []int) [][]int {
    _len := len(groupSizes)
    var re [][]int
    if 0 != _len {
        for i := 0; i < _len; i++ {
            need := groupSizes[i]
            if 0 == need {
                continue
            } else if 1 == need {
                var tmp []int
                re = append(re, append(tmp, i))
            } else {
                var tmp []int
                tmp = append(tmp, i)
                need--
                for j := i+1; need > 0 && j < _len; j++ {
                    if groupSizes[i] == groupSizes[j] {
                        groupSizes[j] = 0
                        tmp = append(tmp, j)
                        need--
                    }
                }
                re = append(re, tmp)
            }
        }
    }
    return re
}
```
![image.png](https://pic.leetcode-cn.com/e7a9f6963e76344e76cebb44448ad96a28dbb467a1189344215cd28c67ac7423-image.png)

# 分析
- 时间复杂度：我认为是$O(k*n)$（$k$是最大组成员个数，可能不对，太菜...）
- 空间复杂度：$O(n)$