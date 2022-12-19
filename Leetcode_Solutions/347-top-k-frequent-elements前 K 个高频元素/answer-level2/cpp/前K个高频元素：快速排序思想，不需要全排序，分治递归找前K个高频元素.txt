1、哈希映射统计元素频率
2、不需要对所有元素进行排序，只需要找到前K高频元素即可；利用快速排序的思想，考虑快速排序的划分过程，在快速排序的“划分”结束后，数列（s[left]....s[right])  被分成了(s[left]..s[i-1])  和(s[i], s[right])  ，此时可以按照右边元素的个数（large = right - i + 1  ）和 k 的大小关系来判断是只在右边还是一部分在右边一部分在左边， 递归地求解；
3、设 large为右半部分元素的数量，则如果large >= K, 那么需要找的元素一定全部在右半部分，则对右半部分递归求解； 如果large < K， 则需要找的元素有K-large个在左半部分，剩下的全在右半部分，对左半部分和右部分递归调用，然后合并返回值即可。
   递归结束条件就是，待排序的数组size小于等于K

代码如下，本地调试通过，但力扣上 有个用例一直过不了，请教大神是怎么回事？
{3,0,1,0}  K=1， 预期结果{0}， 力扣上输出是{3,1,0} （本地IDE调试，输入结果是{0}）

```
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<pair<int, int>> diffNum;
        unordered_map<int, int> numsCnt;
        for (auto i : nums) {
            numsCnt[i]++;
        }

        for (auto i : numsCnt) {
            diffNum.push_back(i);
        }

        return topKF(diffNum, 0, diffNum.size() - 1, k);
    }

    vector<int> topKF(vector<pair<int, int>>& diffNum, int left, int right, int k)
    {
        vector<int> ans;
        int size = right - left + 1;
        if (size <= k) {
            for (int i = left; i <= right; i++) {
                ans.push_back(diffNum[i].first);
            }
            return ans;
        }

        int mid = left + (right - left) / 2;
        swap(diffNum[left], diffNum[mid]);
        int i = left;
        for (int j = left + 1; j <= right; j++) {
            if (diffNum[j].second < diffNum[left].second) {
                i++;
                swap(diffNum[i], diffNum[j]);
            }
        }
        swap(diffNum[left], diffNum[i]);

        int large = right - i + 1;
        ans = topKF(diffNum, i, right, large);
        if (large < k) {
            vector<int> leftNum = topKF(diffNum, left, i - 1, k - large);
            ans.insert(ans.end(), leftNum.begin(), leftNum.end());
        }

        return ans;
    }
};
```

