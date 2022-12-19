#### 方法一：暴力

枚举数组里的每个数字，遍历数组统计有多少数字比当前数字小即可，公式化说，就是对于第 $i$ 个数字，计算 
$$\sum_{j=0}^{n-1}[\textit{nums}[j]<\textit{nums}[i]]$$ 
我们约定括号中返回一个数字，中括号内表达式为真返回 $1$ ，否则返回 $0$ 。

```C++ []
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec((int)nums.size(), 0);
        for (int i = 0;i < (int)nums.size();++i){
            for (int j = 0;j < (int)nums.size();++j){
                if (nums[j] < nums[i]) vec[i]++;
            }
        }
        return vec;
    }
};
```
```Python []
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        n = len(nums)
        vec = [0] * n
        for i in range(n):
            vec[i] = sum(1 for j in range(n) if nums[j] < nums[i])
        return vec
```
**复杂度分析**

- 时间复杂度：枚举数组里的每个数字为 $O(n)$ ，遍历数组也为 $O(n)$，所以总时间复杂度为两者相乘，即 $O(n^2)$ ，其中 $n=nums.length$ 。

- 空间复杂度：$O(1)$ ，不需要使用额外的空间。

#### 方法二：频次数组 + 前缀和

注意到数字的值域范围为 $[0,100]$ ，所以可以考虑建立一个频次数组 $cnt[i]$ ，表示数字 $i$ 出现的次数，那么对于数字 $i$ 而言，它的答案就是 

$$\sum_{j=0}^{i-1}cnt[j]$$

即小于它的数字出现个数之和，直接算需要遍历 $[0,i-1]$ 的 $cnt$ 求和，仍需要线性的时间去计算，但我们注意到这个答案是一个前缀和，所以我们可以再对 $cnt$ 数组求前缀和。那么对于数字 $i$ 的答案就是 $cnt[i-1]$ ，算答案的时间复杂度从 $O(n)$ 降到了 $O(1)$ 。

最后整个算法流程为：遍历数组元素，更新 $cnt$ 数组，即 `cnt[nums[i]]+=1` ，然后对 $cnt$ 数组求前缀和，最后遍历数组元素，对于相应的数字 $O(1)$ 得到答案即可。

```C++ []
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101, 0);
        vector<int> vec((int)nums.size(), 0);
        for (int i = 0;i < (int)nums.size(); ++i){
            cnt[nums[i]]++;
        }   
        for (int i = 1;i <= 100; ++i) cnt[i] += cnt[i-1]; // 求前缀和
        for (int i = 0;i < (int)nums.size(); ++i){
            if (nums[i]) vec[i] = cnt[nums[i] - 1];
        } 
        return vec;
    }
};
```
```Python []
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        n = len(nums)
        cnt, vec = [0] * 101, [0] * n
        for num in nums:
            cnt[num] += 1
        for i in range(1, 101):
            cnt[i] += cnt[i - 1]
        for i in range(n):
            if nums[i]:
                vec[i] = cnt[nums[i] - 1]
        return vec
```
**复杂度分析**

- 时间复杂度：统计 $cnt$ 数组的前缀和需要 $O(S)$ 的时间，遍历数组需要 $O(n)$ 的时间，所以总时间复杂度为 $O(S+n)$ ，其中 $S$ 为值域大小，$n=nums.length$ 。

- 空间复杂度：$O(S)$ ，需要开一个值域大小的数组。

#### 方法三：排序

我们将 $nums$ 数组按数字大小从小到大排序，那么对于第 $i$ 个数字 $x$ ，数组中在它前面的数字一定小于等于它，而题目要求小于它的数字个数，所以我们可以对于位置 $i$ 记录一个变量 $pre_i$ ，表示位置 $i$ 往前第一个不等于 $x$ 的数字下标。对于数字 $x$ ，答案就是 $pre_i+1$ ，因为数组下标是从 $0$ 开始的，所以需要额外加一。$pre_{i}$ 需要分两种情况更新，如果前面一个数字等于当前数字 $x$ ，那么 $pre_i=pre_{i-1}$ ，否则 $pre_i=i-1$ ，这样即能 $O(1)$ 推出 $pre_i$ 。

同时注意到 $pre_i$ 只与前一个位置有关，所以可以不用数组存 $pre_i$ ，直接用一个变量 $pre$ 表示前一个位置的 $pre_{i-1}$ ，然后不断更新 $pre$ 即可。

最后整个算法流程为：对每个数字用一个二元组 $(number_i,index\ of\ number_i)$ 表示数字大小和数字在 $nums$ 数组中的下标，用 $tmp$ 数组存储所有二元组，按数字 $number_i$ 从小到大排序 $tmp$ 数组，最后遍历 $tmp$ 数组，按上文说的方法的维护 $pre$ 变量，对于 $tmp$ 数组里第 $i$ 个元素的答案，应放在答案数组中的第 $index\ of\ number_i$ 个位置里 。

```C++ []
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = (int)nums.size();
        vector<pair<int,int> > tmp;tmp.clear();
        vector<int> vec(n, 0);
        for (int i = 0;i < n; ++i){
            tmp.push_back(make_pair(nums[i], i));
        }
        sort(tmp.begin(), tmp.end());
        int pre = -1;
        for (int i = 0;i < n; ++i){
            if (i == 0) vec[tmp[i].second] = pre + 1;
            else if (tmp[i].first == tmp[i-1].first) vec[tmp[i].second] = pre + 1;
            else{
                pre = i - 1;
                vec[tmp[i].second] = pre + 1;
            }
        }
        return vec;
    }
};
```
```Python []
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        n = len(nums)
        vec = [0] * n
        tmp = sorted([(nums[i], i) for i in range(n)])
        
        pre = -1
        for i in range(n):
            if i != 0 and tmp[i][0] != tmp[i - 1][0]:
                pre = i - 1
            vec[tmp[i][1]] = pre + 1
        return vec

```
**复杂度分析**

- 时间复杂度：排序需要 $O(n\log n)$ 的时间复杂度，遍历数组需要 $O(n)$ 的时间复杂度，所以总的时间复杂度为 $O(n\log n+n)=O(n\log n)$。

- 空间复杂度：上文提及的 $tmp$ 数组需要 $O(n)$ 的空间，空间复杂度为 $O(n)$  。