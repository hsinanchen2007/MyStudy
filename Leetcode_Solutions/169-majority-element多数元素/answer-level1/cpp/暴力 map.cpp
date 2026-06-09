![image.png](https://pic.leetcode-cn.com/674bd47698e822d2311fbdf9d3acc5bc20e2a2f92f34cc9caa38fce86a23a70f-image.png)

### 解题思路 & 代码思路
1、用map存起来，key对应的值就是该key的数量；
2、因为题目交代数组一定非空，且一定存在多数元素，那么当key的数量>n/2时，该key就是多数元素。

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> record;
        int result;
        for(int i = 0; i < nums.size(); i++){
            record[nums[i]]++;
            if(record[nums[i]] > (nums.size() / 2)){
                result = nums[i];
                break;
            }
        }
        return result;
    }
};
```