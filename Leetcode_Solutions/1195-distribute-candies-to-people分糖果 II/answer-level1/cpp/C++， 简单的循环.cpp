### 解题思路
关键就在于每次分发的糖果比上次多一个，剩余的糖果如果不能满足这个条件，就全部分掉。定义相关变量，循环起来即可。

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> peoples(num_people, 0);

        int add = 1;
        while (candies > 0) {
            for (int i = 0; i < num_people; i++) {
                if (candies - add < 0) {
                    add = candies;
                }
                peoples[i] += add;
                candies -= add;
                add += 1;
            }
        }
        return peoples;
    }
};
```