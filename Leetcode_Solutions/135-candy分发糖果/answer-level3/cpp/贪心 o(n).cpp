### 解题思路

思路：贪心
一、思路和官方题解差不多，考虑了两种解法
1、每个孩子往左右看，rating需要比左右孩子中rating小的（可能1个也可能是2个）孩子中最大糖果数大1
2、这样存在一个问题，从左往右遍历完后得到一组结果，这个时候的结果可能是不正确的，轮到右边孩子左右看的时候，糖果数是可变的，因此需要增加一个条件识别整个分配是否处于稳定
3、当然，这样是o(n^2)，会超时

二、拆开为两种情况，从左遍历获取最大糖果和从右遍历最大糖果
1、如果题目修改为只看左边孩子，rating比左边孩子大的话，需要的糖果数比左边孩子的大1，那么可以得到所有孩子的糖果数
2、如果题目修改为值看右边孩子，rating比右边孩子大的话，需要的糖果数比右边孩子的大1，那么可以得到所有孩子的糖果数
3、两种情况合并的时候，由于当前孩子只会受到左右孩子的影响，两边得到的其实都是最合适的结果，那么需要同时满足题目要求时，也就是上两种条件的&值，也就是需要当前孩子左右条件的最大值即为最合适的值。
4、时间复杂度算是o(n)

44ms 17.9M
--- wangtao HW-2020/3/27

### 超时

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candidate(n, 1);

        int flag = true;
        while(flag) {
            flag = false;
            for (int i = 0; i < n; i++) {
                if (i != n - 1 && ratings[i] > ratings[i+1] && candidate[i] <= candidate[i+1]) {
                    candidate[i] = candidate[i+1] + 1;
                    flag = true;
                }
                if (i > 0 && ratings[i] > ratings[i-1] && candidate[i] <= candidate[i-1]) {
                    candidate[i] = candidate[i-1] + 1;
                    flag = true;
                }
            }
        }
        return accumulate(candidate.begin(), candidate.end(), 0);
    }
};
```

### AC

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left2right(n, 1);
        vector<int> right2left(n, 1);
        vector<int> ans(n, 0);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                left2right[i] = left2right[i-1] + 1;
            }
        }
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                right2left[i] = right2left[i+1] + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            ans[i] = max(left2right[i], right2left[i]);
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};
```

