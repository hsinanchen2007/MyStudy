### 解题思路
官方思路中的滑窗思路。
（实现不够优雅。实现时边界移动的操作总是容易漏掉。）

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        vector<int> tmp;

        int l=1, r=2;                   // 滑窗边界，左i，右j
        int sum = 3;                    // 滑窗内序列和大小
        tmp.push_back(1);
        tmp.push_back(2);
        while(l < r) {
            if(sum < target) {      // 右边界移动
                r++;
                sum += r;
                tmp.push_back(r);
            }
            else if(sum > target) {
                tmp.erase(tmp.begin()); // 左边界移动
                sum -= l;
                l++;
            }
            else {                      // 删除操作需要O(tmp.size())复杂度
                ans.push_back(tmp);
                tmp.erase(tmp.begin()); // 找到一组序列，同时左右边界移动
                sum -= l;
                l++;
                r++;
                sum += r;
                tmp.push_back(r);
            }
        }
        return ans;
    }
};
```
![12.png](https://pic.leetcode-cn.com/ab0455636ae10ea52ac70d395475b12ab04c06a6c0d41765d619570b10b1e899-12.png)
