# 1. 理解
这道题一开始的思路是bfs，但是没有结合动态规划，即没有保存中间结果，导致计算超时。在使用一个数组保存中间结果后，顺利AC。
# 2. 思路
1. bfs的终止条件，n小于等于3，此时的解是(n-1);
2. 不然则广度搜索下一端是i[1到n-1]的解j，和不剪i时对比，保存不减的值i和搜索到的解j两者的最大值为长度为i的绳子的最佳答案。
# 3. 代码
```c++ []
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> ms(n+1);
        return bfs(n, ms);
    }

    int bfs(int n, vector<int>& ms){
        if(n <= 3) return n-1;
        if(ms[n]) return ms[n];
        int max=0,sum1,sum2;
        for(int i=1; i<n; i++){         
            sum1 = i;
            sum2 = bfs(i, ms);
            ms[i] = sum2 > sum1 ? sum2 : sum1;
            if(sum1*(n-i) > max) max = sum1*(n-i);
            if(sum2*(n-i) > max) max = sum2*(n-i);
        }
        return max;
    }
};
```
# 4. 总结
广度搜索先要确定前缀的所有可能，递归地给出所有前缀的可能，然后给出最优解。这道题在解大数的时候会用到小数的解，所以保存中间结果供之后使用，这就是动态规划的思想。