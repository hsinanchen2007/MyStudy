### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        return  *min_element(numbers.begin(),numbers.end());

    }
};
```