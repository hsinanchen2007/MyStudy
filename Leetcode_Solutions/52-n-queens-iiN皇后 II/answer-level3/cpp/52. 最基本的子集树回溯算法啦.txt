### 解题思路
这题是n皇后问题的最简单形式了吧。
本题我也做了一些注释。
还有问题的话可以看我上一题的[题解](https://leetcode-cn.com/problems/n-queens/solution/zi-ji-shu-wen-ti-by-liujin-4/)，注释更加详细！
有收获的话请点赞！
### 代码

```cpp
class Solution {
private:
    int count; // 计数值，找到解就++，最后返回即可
    int n; // 存储最初传入的n，也就是将参数值转为全局的，这样减少参数传递。
    vector<int> x; // 存储当前的（可能还未完成的）解
public:
    int totalNQueens(int n) {
        // 这道题比上一道更简单啊！不用存储解的结果，找到可行解就计数就完事了。 
        // 不用存储所有的解，更不用转换。
        this->n = n;  // 将参数n置位全局变量
        dfs(0);  // 判断第0行的皇后放在第几列，深度优先搜索
        return count;
    }
    void dfs(int k){ // 决定第k行的皇后放在第几列
        if(k == n) { // 这时候说明前面有n行的皇后都被防止好了，那就计数呗
            count++;
            return ;
        }
        for(int i=0; i<n; i++){
            x.push_back(i);
            if(placeTest(k)){
                dfs(k+1);    // 决定第k+1行的皇后放在哪个位置。
            }
            x.pop_back();
        }
    }
    bool placeTest(int k){ // 判断第k行的当前放置方案是否合理。
    // 由于是“自底向上”放置并判断的，所以只要判断前面每一行的放置和当前行的放置是否冲突即可
        for(int i=0; i<k; i++){
            if(x[i]==x[k] || x[i]-x[k]==i-k || x[i]-x[k]==k-i){
                return false;
            }
        }
        return true;
    }
};
```
