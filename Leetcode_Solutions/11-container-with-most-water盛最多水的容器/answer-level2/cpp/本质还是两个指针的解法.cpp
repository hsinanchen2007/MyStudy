### 解题思路
刷题，首先不要想着一次性就给出最优解决，而是想一个解决方法。
这道题最暴力的方法，显然是O(n^2)，对数组中每一对元素都算出面积，然后维护一个变量，保存最大的面积。
暴力方法虽然过不了，但是我们可以基于这个方法，想办法对暴力方法优化，来逼近最优解。
对于i,j之间最大的面积Max_S(i,j)有以下公式
Max_S(i,j)  
            = max(S(i,j), Max_S(i, j-1)) if(A[i] > A[j])
            = max(S(i,j), Max_S(i+1, j)) if(A[i] < A[j])
            = max(S(i,j), Max_S(i-1, j-1)) if(A[i] == A[j])
S(i,j)为i,j作为端点的面积。

先令l=0， r = height.size() - 1，作为遍历起点。这样做的原因是因为这个时候，矩形面积的某一条边已经最大了，这样可以减小搜索空间，
因为l只能向右，r只能向左。

为什么会有这个公式呢？
- 因为S(i,j) = (r-l)*min(height[l], height[r])；
- 我们先考虑height[l] < height[r]。 S(i,j) = (r-l)*height[l]。目标是探索更大的面积。根据公式可以知道，此时S(i,j)与height[r]无关。
r--肯定不行，因为(r-l)一定减小，如果height[r-1] <= height[l], 那么S减小，如果height[r-1] > height[l], S同样减小。
- 因此，在这个情况下，不能减小r，只能增大l。
height[l] > height[r]与height[l] == height[r],也用类似的方法，推一遍就可以了

为什么会想到r左移，l右移的方法？
- 这是vector<int>中很常用的两个指针的方法。


### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0) return 0;
        int l = 0, r = height.size() - 1;
        return func(height, l, r);
    }

    int func(vector<int>& height, int l, int r){
        if(l >= r){
            return 0;
        }
        int cur = (r-l)*min(height[l], height[r]);
        if(height[l] == height[r]){
            return max(cur, func(height, l+1, r-1));
        }else if(height[l] > height[r]){
            return max(cur, func(height, l, r-1));
        }else{
            return max(cur, func(height, l+1, r));
        }
        return 0;
    }
};
```

### 结果
执行用时 : 12 ms , 在所有 C++ 提交中击败了 98.14% 的用户 
内存消耗 : 16 MB , 在所有 C++ 提交中击败了 5.52% 的用户