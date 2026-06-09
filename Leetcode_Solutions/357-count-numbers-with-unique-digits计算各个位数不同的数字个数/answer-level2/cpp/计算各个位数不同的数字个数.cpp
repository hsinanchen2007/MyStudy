### 解题思路
此处撰写解题思路
空间换时间
### 代码

```cpp
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0){
            return 1;
        }
        int count = 1;
        vector<int> v1;
        v1.push_back(0);
        v1.push_back(9);
        v1.push_back(9);
        v1.push_back(8);
        v1.push_back(7);
        v1.push_back(6);
        v1.push_back(5);
        v1.push_back(4);
        v1.push_back(3);
        v1.push_back(2);
        v1.push_back(1);
        vector<int> v2;
        v2.push_back(1);
        for(int i=1;i<=n;i++){
            int countTemp = v2[i-1]*v1[i];
            v2.push_back(countTemp);
            count += countTemp;
        }

        return count;
    }
};
```