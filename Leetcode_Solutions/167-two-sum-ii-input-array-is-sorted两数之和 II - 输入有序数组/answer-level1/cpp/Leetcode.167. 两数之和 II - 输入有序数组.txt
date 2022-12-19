### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // 方法1 hash_map 方法
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() < 2)
            return {};
        int i = 0;
        int j = numbers.size() - 1;
        unordered_map<int, int> m_map;
        for(int k = 0; k < numbers.size(); k++)
            m_map[numbers[k]] = k + 1;
        
        for(int k = 0; k < numbers.size(); k++)
        {
            if(m_map.find(target - numbers[k]) != m_map.end() && m_map[target - numbers[k]] != k + 1)
                return {k+1, m_map[target - numbers[k]]};
        }
        return {};
    }
    //方法 2 双指针法
    vector<int> twoSum(vector<int>& numbers, int target){
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j)
        {
            int s = numbers[i] + numbers[j];
            if(s == target)
                return {i+1, j+1};
            if(s > target)
                --j;
            else
            {
                ++i;
            }
        }
        return {};
    }
};
```