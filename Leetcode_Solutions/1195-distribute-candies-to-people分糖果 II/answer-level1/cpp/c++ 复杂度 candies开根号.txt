### 解题思路
找出n(n+1) / 2 小于candies的最大数 n
按照j % num_people分别加到结果数组result[j % num_people]处
注意最后一个j % num_people 再加上candies - (i-1)*i/2 处理剩余糖果

糖果分配情况如下
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 remain     (总和等于candies)
1 2 3 1 2 3 1 2 3 01 02 03 01 02 03  01        (小朋友编号)

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int i = 1, j = 0;
        vector<int> result(num_people, 0);
        while (i*(i+1)/2 <= candies) {
            result[j++ % num_people] += i;
            i++;
        }
        i--;
        result[j % num_people] += candies - i*(i+1)/2;
        return result;
    }
};
```