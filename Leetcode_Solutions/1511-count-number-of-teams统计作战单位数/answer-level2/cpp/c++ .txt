### 解题思路
首先统计出第i个元素中右边的元素中，比i元素大的个数并记录在less_num[i]中，比i元素小的个数并记录在great_num[i]中，随后遍历所有两个元素的组合，如果第一个元素小于第二个元素，则此种组合的可组合数为第二个元素右边比第二个元素大的个数，否则为比第二个元素小的个数。
总遍历次数小于 n*(n-1)/2

### 代码

```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ret = 0;
        vector<int> less_num(rating.size(), 0);
        vector<int> great_num(rating.size(), 0);
        //统计出每个数，左边元素比起大的个数和比起小的个数的元素
        for (vector<int>::size_type i=0; i<rating.size(); i++) {
            for(vector<int>::size_type j=i+1; j<rating.size(); j++) {
                rating[i] < rating[j] ? great_num[i]++ : less_num[i]++;
            }
        }

        //升序则加比第二个值大的个数，降序则加比第二个值小的个数
        for (vector<int>::size_type i=0; i<rating.size()-2; i++) {
            for (vector<int>::size_type j=i+1; j<rating.size()-1; j++) {
                int kk = ret;
                if (rating[i] < rating[j]) {
                    ret += great_num[j];
                } else {
                    ret += less_num[j];
                }

                if (kk != ret) {
                    cout << i << " " << j << endl;
                }
            }
        }

        return ret;
    }
};
```