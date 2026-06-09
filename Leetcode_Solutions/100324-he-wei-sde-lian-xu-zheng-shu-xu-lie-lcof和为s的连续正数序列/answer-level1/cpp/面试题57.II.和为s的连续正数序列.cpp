### 解题思路
- 核心思路：设置双指针，初始为1和2，然后看两指针间序列和是否等于target（题设已知序列最小含2个数）
- 执行用时：4 ms, 在所有 C++ 提交中击败了86.06%的用户
- 内存消耗：6.8 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>result;
        vector<int>seq;
        int sum=0;
        for(int l=1,r=2;l<r;){
            sum=(l+r)*(r-l+1)/2;
            if(sum==target){
                seq.clear();
                for(int i=l;i<=r;i++){
                    seq.push_back(i);
                }
                result.push_back(seq);
                l++;
            }
            else if(sum<target)r++;
            else l++;
        }
        return result;
    }
};
```