### 解题思路
主要思想是两个排好序的数组逐一比较，记录绝对值，如果绝对值变大停止比较，选a中下一个元素与b中上一个元素（使绝对值最小的那个）重新开始比较，更新对每个a的最小绝对值 ans=min(Min,(long)ans)即为答案
注意，不是简单的O(n^2)，b数组的下标是基本不降的，否则会超时哦

### 代码

```cpp
class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long ans=LONG_MAX,mark=0;
        for(long m:a){
            long Min=LONG_MAX;
            for(int i=mark;i<b.size();i++){
                long delta=labs(m-(long)b[i]);
                if(delta>Min)break;
                else {
                    Min=delta;
                    mark=i;
                }
            }
            ans=min(Min,(long)ans);
        }
        return ans;
    }
};
```