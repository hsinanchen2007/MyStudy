### 解题思路
1. 题目属实简单
2. 我的运行时长太长了8
3. imin标记最小值，push_back了之后就把arr[tmp]变成INT_MAX
![image.png](https://pic.leetcode-cn.com/27a3ecf0f9b311e252f6fc6333ca33d1f29aeaf69cdd5f39bd25834e67f30617-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        int tmp;
        while(ans.size()!=k)
        {
            int imin=INT_MAX;
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]<imin)
                {
                    imin=arr[i];
                    tmp=i;
                }
            }
            arr[tmp]=INT_MAX;
            ans.push_back(imin);
        }
        return ans;
    }
};
```