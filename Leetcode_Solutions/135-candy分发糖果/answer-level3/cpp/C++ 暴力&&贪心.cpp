### 解题思路
分为暴力求解 和 贪心算法 两部分
暴力求解即为遍历每一个数进行判断
贪心思想即利用题目要求推得左右两数组遍历后每个位置的最大值即为应分得的糖果这一结论

### 代码

```cpp
/* 暴力求解，直接一遍顺过数组 O(n^2) O(n) */
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        vector<int> candies(ratings.size(),1);
        bool flag = true;
        int sum = 0;
        while (flag) {
            flag = false;
            for (int i = 0; i < ratings.size(); i++) {
                if (i != ratings.size() - 1 && ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                    flag = true;
                }
                if (i > 0 && ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                    flag = true;
                }
            }
        }

        for(int i=0;i<ratings.size();i++){
            sum += candies[i];
        }

        return sum;
    }
};


/* 贪心思想 线性复杂度 O(n) O(n)  从左往右和从右往左去满足更多糖果的条件，最后再取两数组各位置最大值之和即可 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        vector<int> left(ratings.size(),1);
        vector<int> right(ratings.size(),1);
        int sum = 0;

        for (int i = 1; i < ratings.size(); i++) {
            if ( ratings[i] > ratings[i-1]) {
                left[i] = left[i-1] + 1;
            }
        }
        for (int i = ratings.size()-2; i >=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                right[i] = right[i+1] + 1;
            }
        }
        for(int i=0;i<ratings.size();i++){
            sum += std::max( left[i], right[i]);
        }

        return sum;
    }
};
```