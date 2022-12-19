
### 思路
就是将nums[i]与数组中存在的nums[i-1],nums[i+1]合并成一个集合，最后返回最大的那个集合就好。
### 细节实现
为了将每一个数字都存储下来，需要一个映射，通过hashMap将nums[i] 映射成 i，

这样就将很大的数字的合并转化成范围小的数组下标的合并。

### 代码


```c++
class Solution {
public:
    class unionSet{
    private:
        int ans;
        vector<int> fa;
        vector<int> size;
        unordered_map<int, int> hashMap;
        void __merge(int a, int b) {
            int aa = get(a), bb = get(b);
            if (aa == bb) return;
            fa[aa] = bb;
            size[bb] += size[aa];
            ans = max(ans, size[bb]);
        }
    public:
        unionSet(int n = 0): ans(1), fa(n), size(n, 1) {
            for(int i = 0; i < n; i++) fa[i] = i;
        }
        int set(int i, int ind) {
            if (hashMap.find(i) != hashMap.end()) return 1;
            hashMap[i] = ind;
            return 0;
        }
        int get(int x) {
            return fa[x] = (fa[x] == x ? x : get(fa[x]));
        }
        int maxSize() {
            return ans;
        }
        void merge(int a, int b) {
            auto i = hashMap.find(b);
            if (i == hashMap.end()) return; 
            __merge(a, i->second);
        }
    };
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unionSet u(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (u.set(nums[i], i)) continue;
            u.merge(i, nums[i] - 1);
            u.merge(i, nums[i] + 1);
        }
        return u.maxSize();
    }
};
```
执行用时 :
16 ms
, 在所有 C++ 提交中击败了
83.40%
的用户