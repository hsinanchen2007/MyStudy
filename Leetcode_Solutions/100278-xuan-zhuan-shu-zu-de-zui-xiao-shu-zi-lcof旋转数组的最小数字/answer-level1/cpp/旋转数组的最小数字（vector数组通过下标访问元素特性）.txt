### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) 
    {
        int len=numbers.size();
        int min=numbers[len-1];

        if (len==1)
            return min;
        for (int i=len-2; i>=0; --i)
        {
            //min=min < numbers[i] ? min:numbers[i];
            if (min < numbers[i])
            {
                return min;
            }
            min=numbers[i];
        }
        return min;
    }
};
```