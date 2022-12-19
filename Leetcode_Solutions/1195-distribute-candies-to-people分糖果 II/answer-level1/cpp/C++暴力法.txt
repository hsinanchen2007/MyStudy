### 解题思路
此处撰写解题思路
没啥解释的..
### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
            int n=1;
            vector<int> a(num_people,0);;
            while(candies > n)
            {
                a[(n-1)%num_people] += n;
                candies -= n;
                n++;
            }
            a[(n-1)%num_people] += candies;
            return a;

    }
};
```