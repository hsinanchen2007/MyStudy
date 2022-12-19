# 5369. 统计作战单位数
首先遍历数组rating，从0开始枚举下标 i ，统计**满足 rating[j] < rating[i] 或者 rating[j] > rating[i] ，且 j < i** 的 j 的个数。分别存储在lt[i] 和 gt[i] 中。时间复杂度 O(n^2)。
然后遍历 lt 和 gt，从 0 开始枚举下标 i，累加满足 **rating[j] < rating[i] 且 j < i ** 的 lt[j]，累加满足 **rating[j] > rating[i] 且 j < i** 的 gt[j]。
```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt[2][200] = {0};
        for(int i = 1; i < rating.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(rating[j] < rating[i]) {
                    cnt[0][i]++;
                } else if(rating[j] > rating[i]) {
                    cnt[1][i]++;
                }
            }
        }
        int anw = 0;
        for(int i = 1; i < rating.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(rating[j] < rating[i]) {
                    anw += cnt[0][j];
                } else if(rating[j] > rating[i]) {
                    anw += cnt[1][j];
                }
            }
        }
        return anw;
    }
};
```
# 扫码关注 及时获取全部题解
![qrcode_for_gh_6e5f8557b1f8_258.jpg](https://pic.leetcode-cn.com/684891c77d175fbff267708d98d0e3c5cbfc9e0e038cc036e2284dccd311359f-qrcode_for_gh_6e5f8557b1f8_258.jpg)
