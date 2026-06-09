### 解题思路
序列必是 **[i, i+1, i+2, ..., i+k]** 公差为1的等差数列 
所以 等差数列求和 ans = (i + (i+k))*(k+1)*0.5 
观察各序列发现每个k所对应的i 一定小于 floor(target/2) =>  1 =< i <= target/2
因此枚举 k>=1 所对应的首项 i∈[1, floor(target/2)]
首项为i的序列和不等于target 说明不存在，跳过。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if(target<1) return vector<vector<int>>();
        vector<vector<int>> ser;
        // t = i + (i+1) + (i+2) + ... +(i+k)    t = (k+1)*i + k*(k+1)*0.5   k>=1
        // i = t/(k+1) - 0.5*k 
        // 1 <= k  1 <= head <= t/2
        int k = 1; //每个序列k+1项 k+1>=2 k>=1
        int head = 0;
        while(2*head <= target)
        {
            head = (int)((target - 0.5*k*(k + 1)) / (k + 1));
            int ans = (2*head + k)*(k+1)*0.5;
            if(head<=0) break;
            if(ans != target) {k++; continue;}
            vector<int> cur(k+1);
            for(int i = 0; i < k + 1; i++)
            {
                cur[i] = head + i;
            }
            //ser.insert(ser.begin(), cur);
            ser.push_back(cur);
            k++;
        }
        reverse(ser.begin(), ser.end());
        return ser;
    }
};
```