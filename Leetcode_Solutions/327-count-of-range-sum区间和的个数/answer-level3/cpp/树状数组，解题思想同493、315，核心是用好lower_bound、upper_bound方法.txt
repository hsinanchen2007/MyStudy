class Solution {
public:
    int Query(vector<int> &bit, int index)
    {
        int size = bit.size();
        int num = 0;
        while(index > 0) {
            num += bit[index];
            index -= index & (-index);
        }
        return num;
    }

    void Update(vector<int> &bit, int index, int value) 
    {
        int size = bit.size();
        while (index < size) {
            bit[index] += value;
            index += index & (-index);
        }
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        vector<long long> pre(size + 1, 0);
        vector<int> bit(size + 2, 0);
        pre[0] = 0; // 必须包含，否则s[i, j] = pre[j] - pre[i - 1]区间和不能表达s[0, 0] = nums[0]自身
        for (int i = 0; i < size; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        vector<long long> copypre(pre);
        sort(copypre.begin(), copypre.end());
        /*
            区间和S[i, j] = pre[j] - pre[i - 1] 在 [lower, upper] 之间的个数等价于:
            求pre[i - 1]的个数z，约束条件：pre[j] - upper <= pre[i - 1] <= pre[j] - lower
            设pre[i - 1] = p[k]， k < j：
            pre[k] <= pre[j] - lower     满足条件的pre[k]有x个
            pre[k] <= pre[j] - upper - 1 满足条件的pre[k]有y个
            则同时满足以上条件求得z = x - y
            x和y通过树状数组计算：
        */
        int res = 0;
        for (int j = 0; j < size + 1; j++) {
            int index1 = upper_bound(copypre.begin(), copypre.end(), pre[j] - lower) - copypre.begin() - 1 + 1;
            int index2 = upper_bound(copypre.begin(), copypre.end(), pre[j] - upper - 1) - copypre.begin() - 1 + 1;
            res += Query(bit, index1) - Query(bit, index2);

            int index = lower_bound(copypre.begin(), copypre.end(), pre[j]) - copypre.begin() + 1;
            Update(bit, index, 1);  //因为k < j，update操作放在query之后
        }
        return res;
    }
};