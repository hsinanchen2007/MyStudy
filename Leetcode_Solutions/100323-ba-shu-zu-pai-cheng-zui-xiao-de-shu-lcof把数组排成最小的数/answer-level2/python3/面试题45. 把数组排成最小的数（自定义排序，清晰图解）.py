#### 解题思路：

- 此题求拼接起来的 “最小数字” ，本质上是一个排序问题。
- **排序判断规则：** 设 $nums$ 任意两数字的字符串格式 $x$ 和 $y$ ，则
  - 若拼接字符串 $x + y > y + x$ ，则 $m > n$ ；
  -  反之，若 $x + y < y + x$ ，则 $n < m$ ；
- 根据以上规则，套用任何排序方法对 $nums$ 执行排序即可。

![Picture1.png](https://pic.leetcode-cn.com/5f7afd0b198405c178c41e1f60a2b54037f2a931a3df6a4056bc908c902aa567-Picture1.png){:width=450}

##### 算法流程：

1. **初始化：** 字符串列表 $strs$ ，保存各数字的字符串格式；
2. **列表排序：** 应用以上 “排序判断规则” ，对 $strs$ 执行排序；
3. **返回值：** 拼接 $strs$ 中的所有字符串，并返回。

**复杂度分析：**

- **时间复杂度 $O(N \log N)$ ：** $N$ 为最终返回值的字符数量（ $strs$ 列表的长度 $\leq N$ ）；使用快排或内置函数的平均时间复杂度为 $O(N \log N)$ ，最差为 $O(N^2)$ 。
- **空间复杂度 $O(N)$ ：** 字符串列表 $strs$ 占用线性大小的额外空间。

<![Picture2.png](https://pic.leetcode-cn.com/10dbbc9295fff9208cdb76d0d9e1a354f3bb509e16f56f2745ba305116d9ea5a-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/6a40247b792263645986777f05d01175a9aab079158720e941aaa51bf845d6e6-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/e9adae04fff102919b9db2647f73db97927b1319392610476c1f810c0ae5360a-Picture4.png)>

#### 代码：

- 本文只列举 **快速排序** 和 **内置函数** 两种排序方法，其他方法也可使用。

##### 快速排序：

- 需修改快速排序函数中的排序判断规则。字符串大小（字典序）对比的实现方法：
  - Python 中可直接用 `<` , `>` ；
  - Java 中使用 `A.compareTo(B)` 。

```python []
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        def fast_sort(l , r):
            if l >= r: return
            i, j = l, r
            while i < j:
                while strs[j] + strs[l] >= strs[l] + strs[j] and i < j: j -= 1
                while strs[i] + strs[l] <= strs[l] + strs[i] and i < j: i += 1
                strs[i], strs[j] = strs[j], strs[i]
            strs[i], strs[l] = strs[l], strs[i]
            fast_sort(l, i - 1)
            fast_sort(i + 1, r)
        
        strs = [str(num) for num in nums]
        fast_sort(0, len(strs) - 1)
        return ''.join(strs)
```

```java []
class Solution {
    public String minNumber(int[] nums) {
        String[] strs = new String[nums.length];
        for(int i = 0; i < nums.length; i++)
            strs[i] = String.valueOf(nums[i]);
        fastSort(strs, 0, strs.length - 1);
        StringBuilder res = new StringBuilder();
        for(String s : strs)
            res.append(s);
        return res.toString();
    }
    void fastSort(String[] strs, int l, int r) {
        if(l >= r) return;
        int i = l, j = r;
        String tmp = strs[i];
        while(i < j) {
            while((strs[j] + strs[l]).compareTo(strs[l] + strs[j]) >= 0 && i < j) j--;
            while((strs[i] + strs[l]).compareTo(strs[l] + strs[i]) <= 0 && i < j) i++;
            tmp = strs[i];
            strs[i] = strs[j];
            strs[j] = tmp;
        }
        strs[i] = strs[l];
        strs[l] = tmp;
        fastSort(strs, l, i - 1);
        fastSort(strs, i + 1, r);
    }
}
```

##### 内置函数：

- 需定义排序规则：
  - Python 定义在函数 `sort_rule(x, y)` 中；
  - Java 定义为 `(x, y) -> (x + y).compareTo(y + x)` 。

```python []
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        def sort_rule(x, y):
            a, b = x + y, y + x
            if a > b: return 1
            elif a < b: return -1
            else: return 0
        
        strs = [str(num) for num in nums]
        strs.sort(key = functools.cmp_to_key(sort_rule))
        return ''.join(strs)
```

```java []
class Solution {
    public String minNumber(int[] nums) {
        String[] strs = new String[nums.length];
        for(int i = 0; i < nums.length; i++) 
            strs[i] = String.valueOf(nums[i]);
        Arrays.sort(strs, (x, y) -> (x + y).compareTo(y + x));
        StringBuilder res = new StringBuilder();
        for(String s : strs)
            res.append(s);
        return res.toString();
    }
}
```