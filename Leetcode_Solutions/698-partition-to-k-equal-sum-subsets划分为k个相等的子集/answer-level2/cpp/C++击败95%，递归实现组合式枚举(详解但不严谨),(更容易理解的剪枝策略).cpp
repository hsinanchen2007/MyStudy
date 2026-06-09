## 题意
将原来的数组$nums$划分称为k个非空子集。每一个子集的和都为$target$,其中$target$可以由数组元素总和除以$k$得到。

## 算法
采用暴力搜索的方式对于每种集合划分方式进行枚举，如果可以正好划分称为$k$的和为$target$的子集，则返回$true$，否则返回$false$。
为了穷举每种集合划分方式，我们可以维护一个`vector<int> path`，长度为$k$，其中$path[i]$表示第$i$个集合的总和。
从前到后枚举每一个数字$nums[u]$，尝试将$nums[u]$加入到其中某一个集合内，直到枚举到集合尾部时，如果每一个子集之和均为$target$，则返回为$true$。
同时，由于集合内元素都为正整数，如果某一个子集之和大于$target$，可以直接返回$false$。换句话说，只有在$nums[u]+path[i]\le target$的时候才尝试将$nums[u]$加入。
换句话说保证了已有的集合中一定没有$\gt target$的子集，那么只需要保证正好划分为$k$个$\le target$的子集，即可证明这$k$个集合中每个集合之和都为$target$。

### 时间复杂度分析（粗略不严谨）
每一个数字有$k$种选法，一共有$n$个数字，所有划分方式有$k^n$种，本题的范围为$1\le k \le n \le 16$，故最大可能有$16^{16}\approx 1.8 \times10^{19}$种可能，显然超出了我们的承受范围。
同时注意到，本题子集的划分顺序不分先后，实际上编号为$1-n$并没有区别。即我们前面的枚举方式对于不同的排列顺序有着大量的重复。其中每一种组合式的划分方式大约可以对应$A_{k}^{k}$种排列方式，显然造成了大量的重复枚举。
假设我们可以排除掉组合式的枚举方式，大约只需要 $\frac{k^n}{k!}$，最多约$\frac{16^{16}}{16!} \approx 8.8 \times10^6$次枚举，这样的计算量显然我们比较能够接受了。

### 具体实现
下面提供一个递归实现组合式枚举的思路：
1. 维护现在已经划分开辟的子集$path$，与前面的不同是不用预先开辟长度$n$的$path$，而是动态的创建新的子集。
2. 每次枚举到一个新的数字$nums[u]$，我们可以采用以下两种决策：
    - 将$nums[u]$加入到已有的某一个集合内，并动态维护该子集之和
    - 开辟一个新的子集，并将$nums[u]$加入到新的集合内部
3. 如果子集个数大于$k$，或剩下的元素不足以构成$k$个集合，直接返回。

### 正确性
可以证明对于每一种排列型枚举方式都可以采用这种方式取得。
假设集合$A_i，i=1\cdots k$表示排列型枚举方式获得的每一种集合。而$A_i = \left \{a_{ij}|j=1,2,\cdots \right \}$。
首先维护一个空的`vector<int> path`，$path$中的每一个元素代表某个集合$A_i$，我们从左到右枚举每一个$nums[u]$，通过查看它处于集合哪个集合$A_i$中，若此集合已经在$path$中，我们将`path+=num[u]`，否则我们创建一个新的集合，并且规定这个新的集合就对应于前面得到的那个集合$A_i$。通过这样的方式，我们可以知道每一种排列方式都可以对应于这里的一个$path$，同时，同样的$path$可以同时对应于多个排列型枚举方式。
而且，对于$nums$中的任意两个元素$nums[i],nums[j]$，他们对应于$path$中的标号一定是$id(i)\le id(j)$的，这样的枚举方式过滤掉了大量重复。

## 优化
然鹅即便实现了上述的组合型枚举算法，仍然还是会TLE，这一方面是因为我们的计算不够严谨hh。另一方面是提示我们需要加入一些优化/剪枝策略。
-  优化搜索顺序——优先搜索分支少的方向：由于我们只会将新来的数加入到可以加入的集合，即满足`nums[u]+path[i]<=target`。因此`path[i]`越少对应的分支数会越少。因此采用从大到小的枚举方式进行枚举。

实验证明对于这题的样例来说，这个优化足够强大，加上这个优化不仅可以过掉题目，甚至可以击败90%的吃瓜群众。

## 代码

```
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target = 0;
        for(auto x:nums) target += x;
        if(target%k) return false;
        target /= k;
        
        sort(nums.begin(),nums.end(),greater<int>());
        
        int n = nums.size();
        vector<int> path;
        
        function<bool(int)> dfs = [&] (int u) {
            if(u==n) return true;
            if(nums[u] > target) return false;
            
            for(int i = 0 ; i < path.size() ; i++) {
                if(path[i] + nums[u] > target) continue;
                path[i]+=nums[u];
                if(dfs(u+1)) return true;
                path[i]-=nums[u];
            }
            if(path.size() == k) return false;
            
            path.push_back(nums[u]);
            if(dfs(u+1)) return true;
            path.pop_back();
            return false;
        };
        return dfs(0);
    }
};
```

### （彩蛋？）最后写一个看到这题之后的直觉解法，虽然比较慢但是依然是可以过的，甚至更容易理解
直接枚举每一个集合进行求和，将所有和为$target$的集合保存起来，然后求取其中若干个集合，他们的交为空，并为整体集合（集合覆盖问题）。下面是代码：
熟悉采用二进制方式枚举所有子集的同学应该很容易$get$到这个写法。

```
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int target = 0;
        for(auto x:nums) target += x;
        if(target % k) return false;
        target /= k;
        
        vector<int> h;

        for(int i = 0 ; i < 1<<n ; i++) {
            int s = 0;
            for(int j = 0 ; j < n ; j++)
                if(i>>j&1)
                    s += nums[j];
            if(s==target) h.push_back(i);
        }
        
        function<bool(int,int)> dfs = [&] (int u, int p) {
            if(u==h.size()) return p == (1<<n)-1;
            
            return dfs(u+1,p) || !(h[u]&p) && dfs(u+1,p|h[u]);
        };
        return dfs(0,0);
    }
};
```

