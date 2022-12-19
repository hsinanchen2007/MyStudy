### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        if (0 == n)
            return {};

        int temp = pow(10,n);//n为1，temp为10，n为2，temp为100

        vector<int> vec;
        for (int i=1; i<temp; i++)
            vec.push_back(i);

        return vec;
    }
};
```