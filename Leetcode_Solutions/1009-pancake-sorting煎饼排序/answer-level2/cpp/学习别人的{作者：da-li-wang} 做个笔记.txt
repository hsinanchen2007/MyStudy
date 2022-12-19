### 解题思路
每次都把当前区间最大的数移动到当前区间的最后面
假设当前区间为[0, i]，该区间内最大的数的下标为j
那么我们可以通过两次翻转达到目的：
1，j + 1，将该数移动到区间头部
2，i + 1，将该数移动到区间尾部

作者：da-li-wang
链接：https://leetcode-cn.com/problems/pancake-sorting/solution/c-jian-dan-shu-xue-fa-by-da-li-wang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

### 代码

```cpp
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int N = A.size();
        vector<int> res;
        for (int i = N - 1; i > 0; --i) {
            int j = max_element(A.begin(), A.begin() + i + 1) - A.begin();
            if (j > 0) {
                reverse(A.begin(), A.begin() + j + 1);
                res.push_back(j + 1);
            }
            reverse(A.begin(), A.begin() + i + 1);
            res.push_back(i + 1);
        }
        return res;
    }
};

```