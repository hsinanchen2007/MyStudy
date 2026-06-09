### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> v(num_people, 0); // 初始化向量，长度为小朋友数
        int candy = 0;
        int i = 0;          // 遍历起点
        while (candies > 0) // 当有糖可发时，给小朋友发糖
        {
            if (candies <= candy + i + 1) // 如果糖不够发了，则把所有糖给这个小朋友然后跳出循环
            {
                v.at(i) += candies;
                break;
            }
            v.at(i) += candy + i + 1;       // 给小朋友发的糖递增
            candies -= (candy + (i++) + 1); // 从总糖果里减去发掉的糖
            if (i == v.size())              // 当给最后一个小朋友发完糖后，重新给第一个小孩子发糖，并且发的糖比上一轮多一个
            {
                i = 0;
                candy += num_people;        // 下一轮第一次发的糖的基数
            }
        }
        return v; // 返回发完糖的小朋友数组
    }
};
```