从删除的方案入手，只需考虑两种情况。
令当前合法前缀长度为`n`，且这个前缀中出现的不同数字的个数为`t`，则每个数字需要出现的次数为`n/t`次。
因此，可以通过记录当前为止，出现`n/t`次的数字的个数是否满足t来判断当前长度`n`是否合法。

`cnt[i]` : 出现i次的数字有多少个。
`cnt_nums[num]`: 数字num出现来多少次。 
`n` : 当前为止不同数字的个数
`len` : 当前遍历到的位置

但是，题目多了一个删除的条件，所以需要分两种情况讨论。
1. 删除只出现1次的数字，例如3 3 2，删除 2。
2. 删除出现不止1次的数字，例如3 3 2， 删除3.

对于1，数字种类会减1，因此合法情况下，每个数字出现的次数为`need = (len-1)/(n-1)`，需要特判一下所有数字都出现1次的情况。
整个序列合法的条件是: `cnt[1] > 0 && n > 1 && (cnt[need] = n-1 || need == 1 && cnt[need]-1 == n-1)`。

对于2， 数字种类不会减少，因此合法情况下，每个数字出现的次数为`need = (len-1)/(n)`, 且出现need+1次的数字只有一个。

整个序列合法的条件是: `cnt[need] == n && cnt[need+1] == 1`。

时间复杂度，空间复杂度均为`O(n)`。

```cpp
class Solution {
public:
    int cnt[100005],num_cnt[100005];
    int n = 0;
    int appear[100005];
    inline void update(int i) {
        cnt[num_cnt[i]]--;
        cnt[++num_cnt[i]]++;
    }
    // 没删掉字符
    inline bool ok(int i) {
        int min_need = i/n;
        if(cnt[min_need] == n-1 && cnt[min_need+1] == 1 ) {
            return true;
        }
        return false;
    }
    
    inline void insert(int i) {
        if(appear[i] == 0) n++;
        appear[i]++;
    }
    // 删掉一个字符
    inline bool ok2(int i) {
        int min_need = i/(n-1);
        if(cnt[min_need] == n-1 || min_need == 1 && cnt[min_need] -1 == n-1)
            return true;
        return false;
    }
    int maxEqualFreq(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            insert(nums[i]);
            update(nums[i]);
            if(cnt[1] && n > 1 && ok2(i) || ok(i)) {
                ans = i+1;                
            } 
        }      
        return ans;
    }
};
```