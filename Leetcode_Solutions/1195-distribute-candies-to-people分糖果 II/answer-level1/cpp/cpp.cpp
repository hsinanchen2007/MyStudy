### 解题思路
用取余操作来模拟循环过程，用数组的话会比vector更快，向量的优点在于操作方便

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int member = 0, num = 1;
        vector<int> res(num_people);
        while (true)
        {
            member = member % num_people;
            if (candies > num)  res[member] += num;
            else    
            {
                res[member] += candies;
                break;
            }
            candies -= num;
            ++num;
            ++member;
        }
        return res;
    }
};
```