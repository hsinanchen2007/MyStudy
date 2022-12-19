### 解题思路

- 暴力枚举
- 等差数列配合双指针判断答案区间

### 代码

#### 等差数列判定区间（官方答案）

```c++
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>vec;
        vector<int> res;
        for (int l = 1, r = 2; l < r;){
            int sum = (l + r) * (r - l + 1) / 2;
            if (sum == target){
                res.clear();
                for (int i = l; i <= r; ++i) res.emplace_back(i);
                vec.emplace_back(res);
                l++;
            }
            else if (sum < target) r++;
            else l++;
        }
        return vec;
    }
};
```

#### 暴力枚举

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> arr = new ArrayList<>();
        int l = 0;
        for (int i = 0; i < target / 2; i++) {
            int j = i + 1;
            int sum = 0;
            List<Integer> subSeq = new ArrayList<>();
            while (sum < target) {
                sum += j;
                subSeq.add(j);
                j++;
            }
            if (sum == target) {
                int[] ints = new int[subSeq.size()];
                for (int k = 0; k < subSeq.size(); k++) {
                    ints[k] = subSeq.get(k);
                }
                arr.add(ints);
                l++;
            }
        }

        int[][] res = new int[l][];
        for (int i = 0; i < l; i++) {
            res[i] = arr.get(i);
        }
        return res;
    }
}
```