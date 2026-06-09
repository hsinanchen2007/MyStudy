```
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // 第一维表示属于第几个数组，第二维表示属于数组的第几个数字
        vector<vector<int>> idx;
        for(int i=0;i<nums.size();i++) {
            for(int j=0;j<nums[i].size();j++) {
                idx.push_back({i, j});
            }
        }
        // 根据数字大小对索引进行排序
        sort(idx.begin(), idx.end(), [&nums](vector<int>& v1, vector<int>& v2) {
            return nums[v1[0]][v1[1]] < nums[v2[0]][v2[1]];
        });
        int n = nums.size();
        // 记录每个数组在当前滑动窗口中的数字个数
        vector<int> cnt(n, 0);
        // 滑动窗口起始位置
        int last = 0;
        // 最大范围为最小数到最大数的区间
        vector<int> res = {nums[idx[0][0]][idx[0][1]], nums[idx.back()[0]][idx.back()[1]]};
        for(int i=0;i<idx.size();i++) {
            cnt[idx[i][0]]++;
            // 判断是否所有数组的数字都出现
            bool valid = true;
            for(int j=0;j<n;j++) if(cnt[j]==0) {
                valid = false; break;
            }
            // 存在未出现的数组
            if(!valid) continue;
            while(last < i) {
                // 更新可能的结果
                int r = nums[idx[i][0]][idx[i][1]];
                int l = nums[idx[last][0]][idx[last][1]];
                if(res[1]-res[0]>r-l) res = {l, r};
                // 某个数组的数字都被清空，则跳出循环
                if(--cnt[idx[last++][0]]==0) break;
            }
        }
        return res;
    }
};
```
