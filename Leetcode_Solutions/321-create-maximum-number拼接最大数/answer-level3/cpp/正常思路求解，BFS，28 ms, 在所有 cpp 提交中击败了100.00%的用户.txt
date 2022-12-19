执行用时 :28 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :11.1 MB, 在所有 cpp 提交中击败了97.06%的用户


先用递归来解释思路：
1. 两个队列各自从头开始寻找；
2. 从队列一寻找，确保队列一剩余的所有元素+队列二当前剩余的所有元素足够的情况下，其余元素种的最大值；
3. 队列二中同理寻找；
4. 取出大的元素，跟踪填写到结果种，调整对应队列的起始位置，重复步骤1；直到k个数都找到完成；
如果两个队列中取得的数字一样大，需要继续取下一个数字处理。

通过DFS递归实现，运行超时；原因是两个队列中的取得的最大数一样的情况比较多。
重新考虑改造成BFS，逐个数字处理，通过。

附上DFS和BFS的代码。
```
class Solution {
    vector<int> nums1;
    vector<int> nums2;

    int findMaxIndex(vector<int> &nums, int idx, int len){
        int maxIdx = idx;
        for (int i = idx; i < nums.size() - len; ++i){
            if (nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
        }
        return maxIdx;
    }

    void dfs(vector<int> &rst, int idx1, int idx2, int k){
        if (k == 0){
            return;
        }

        int len1 = max(0, k - ((int)nums2.size() - idx2)-1);
        int maxIdx1 = findMaxIndex(nums1, idx1, len1);
        // printf("idx1 = %d, len1=%d, maxIdx1=%d\n", idx1, len1, maxIdx1);

        int len2 = max(0, k - ((int)nums1.size() - idx1)-1);
        int maxIdx2 = findMaxIndex(nums2, idx2, len2);
        // printf("idx2 = %d, len2=%d, maxIdx2=%d\n", idx2, len2, maxIdx2);

        if (maxIdx1 == nums1.size()){
            rst.push_back(nums2[maxIdx2]);
            return dfs(rst, idx1, maxIdx2 + 1, k-1);
        }
        else if (maxIdx2 == nums2.size()){
            rst.push_back(nums1[maxIdx1]);
            return dfs(rst, maxIdx1 + 1, idx2, k-1);
        }
        else{
            if (nums1[maxIdx1] > nums2[maxIdx2]){
                rst.push_back(nums1[maxIdx1]);
                return dfs(rst, maxIdx1 + 1, idx2, k-1);
            }
            else if (nums1[maxIdx1] < nums2[maxIdx2]){
                rst.push_back(nums2[maxIdx2]);
                return dfs(rst, idx1, maxIdx2 + 1, k-1);
            }
            else {
                rst.push_back(nums1[maxIdx1]);
                vector<int> rst1, rst2;
                rst1 = rst2 = rst;
                dfs(rst1, maxIdx1 + 1, idx2, k-1);
                dfs(rst2, idx1, maxIdx2 + 1, k-1);

                rst = rst1;
                for (int i = 0; i < rst1.size(); ++i){
                    if (rst1[i] > rst2[i]){
                        break;
                    }
                    else if (rst1[i] < rst2[i]){
                        rst = rst2;
                        break;
                    }
                }
                return;
            }
        }
    }

    void bfs(vector<int> &rst, int k){
        set<pair<int, int>> s1;        
        s1.insert(make_pair(0, 0));

        while (k){
            int maxNum = -1;
            set<pair<int, int>> s2;
            for (auto &p : s1){
                int idx1 = p.first;
                int idx2 = p.second;

                int len1 = max(0, k - ((int)nums2.size() - idx2)-1);
                int maxIdx1 = findMaxIndex(nums1, idx1, len1);
                int maxNum1 = maxIdx1 >= nums1.size() ? -1 : nums1[maxIdx1];
                // printf("idx1 = %d, len1=%d, maxIdx1=%d, maxNum1=%d\n", idx1, len1, maxIdx1, maxNum1);

                if (maxNum1 > maxNum){
                    s2.clear();
                    s2.insert(make_pair(maxIdx1 + 1, idx2));
                    maxNum = maxNum1;
                }
                else if (maxNum1 == maxNum){
                    s2.insert(make_pair(maxIdx1 + 1, idx2));
                }

                int len2 = max(0, k - ((int)nums1.size() - idx1)-1);
                int maxIdx2 = findMaxIndex(nums2, idx2, len2);
                int maxNum2 = maxIdx2 >= nums2.size() ? -1 : nums2[maxIdx2];
                // printf(" idx2 = %d, len2=%d, maxIdx2=%d, maxNum2=%d\n", idx2, len2, maxIdx2, maxNum2);

                if (maxNum2 > maxNum){
                    s2.clear();
                    s2.insert(make_pair(idx1, maxIdx2 + 1));
                    maxNum = maxNum2;
                }
                else if (maxNum2 == maxNum){
                    s2.insert(make_pair(idx1, maxIdx2 + 1));
                }
            }
            s1.swap(s2);
            rst.push_back(maxNum);
            --k;
        }
    }    

public:
    vector<int> maxNumber(vector<int>& a, vector<int>& b, int k) {
        nums1.swap(a);
        nums2.swap(b);

        vector<int> rst;
        //dfs(rst, 0, 0, k);
        bfs(rst, k);
        return rst;
    }
};
```
