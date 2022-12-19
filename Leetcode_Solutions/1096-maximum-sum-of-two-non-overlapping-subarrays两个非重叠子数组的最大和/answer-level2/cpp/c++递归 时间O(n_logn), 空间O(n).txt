# 思路：
1. 使用sums[A.size()+1]数组保存从0-i的和，这样A数组区间下标i~j之间的和只需要使用nums[j]-nums[i]即可计算出；
2. 当L长子区间在M长子区间左侧时，不断的把sums数组分为两部分，分别从左右区间中找L长最大子区间，M长最大子区间；
3. 当M长子区间在L长子区间左侧时，不断的把sums数组分为两部分，分别从左右区间中找M长最大子区间，L长最大子区间；

```c++
class Solution {
private:
    vector<int> sums;
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        if (L + M > A.size()) return 0;
        sums.resize(A.size()+1, 0);
        for (int i = 1; i < sums.size(); i++) sums[i] = sums[i-1] + A[i-1];
        int max_value = 0;
        for (int i = L; i < sums.size()-M;i++){
            max_value = max(max_value, findMax(0, i, L) + findMax(i, sums.size()-1, M));  // 尤其要注意右区间的起始值是i，而不是i+1
        }
        for (int i = M; i < sums.size()-L;i++){
            max_value = max(max_value, findMax(0,i,M) + findMax(i, sums.size()-1, L));
        }
        return max_value;
    }

    // 在sums的[left, right]之间查找最大连续子区间
    int findMax(int left, int right, int length){
        int max_value = 0;
        for (int i = left; i+length <= right; i++) max_value = max(max_value, sums[i+length]-sums[i]);
        return max_value;
    }
};
```