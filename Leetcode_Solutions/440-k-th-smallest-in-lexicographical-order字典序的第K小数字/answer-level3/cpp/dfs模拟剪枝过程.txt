
## 算法思路

- 画出字典树
- k表示要找到后面的第k个元素，起始下标是0
- 获取以prefix开头的数字个数，包括他本身
  - 如果数字个数大于k，下移，在prefix*10下的子树进行查找 
  - 如果数字个数小于等于k，右移，在prefix+1下的子树进行查找

问题的关键是求解 以prefix开头的数字个数，包括他本身

- 根节点 `[prefix, prefix+1 )`
- 第一层 `[prefix*10, (prefix+1)*10 )`
- 第二层 `[prefix*100, min(n+1, (prefix+1)*100) )`
- ...


## 代码实现

```cpp
class Solution {
public:
typedef long long LL;
    int findKthNumber(int n, int k) {
        int prefix = 1;
        k--; // k记录要找的数字在prefix后的第几个
        while (k>0){
            int cnt = getCnt(n, prefix); // 当前prefix 下有多少个元素;包含prefix
            if (cnt <= k) { // 向右
                k -= cnt;
                prefix++;
            } else { // 向下
                k--;
                prefix*=10;
            }
        }
        return prefix;
    }
    int getCnt(LL n, LL prefix){
        LL cnt = 0;
        for (LL first = prefix, second = prefix+1; first<=n; first*=10, second*=10){
            cnt+= min(n + 1, second) - first;
        }
        return cnt;
    }
};
```

![双百](https://pic.leetcode-cn.com/0f80092d17d5f52244f5e39dbd971a3284b4618d72673c5df619cd7b59b33e9c.png)