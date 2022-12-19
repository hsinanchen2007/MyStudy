### 解题思路
这个执行用时怎么计算的？同样的代码提交两次用时不同？

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        while(i != j)
        {
            int tmp=numbers[i]+numbers[j];
            if(tmp == target) return vector<int>{i+1,j+1};
            if(tmp > target) j--;
            else i++;
        }
        return vector<int>{-1,-1};
    }
};
```