### 解题思路
![微信图片_20200226221253.png](https://pic.leetcode-cn.com/81a98b04daf23a5caa3b6befa2eec938ae7ce6be481baca276139850d1c2d998-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200226221253.png)
深度优先搜索的思想。
设置pre值记录前一次递归时的取值，在pre之后进行本次的取值的选择，这样避免数值以及组合的重复。
pos表示当前操作位置，即当前进行的是K个数中的第pos个的取值操作。
利用pre值以及当前位置pos与K的关系进行剪枝（具体操作见代码及注释）
笔记：组合问题和排序问题不同的是，在组合问题中元素的顺序不考虑，只需要从当前位置向后寻找。排序问题每次都需要从头寻找，需要用visited数组记录访问过的元素。


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> list;
        vector<int> result;
        dfs(list,result,n,k,0,-1);       
        return list;
    }
    void dfs(vector<vector<int>>& list, vector<int>& result, int n, int k, int pos,int pre){
        if(pos == k){
            list.push_back(result);
            return;
        }
        if((pos + (n-pre)) <= k)return;//剪枝，添加之后用时节省了2/3
        //在当前对不合理的取值进行判断，结束下一层的递归操作。
        //如果当前剩余可操作数字的个数即（n-pre）< k-pos+1(即组合中有待赋值的位置个数)，（+1是因为当前pos还没有进行操作），则可以判断该条路径不可能得到正确的解，不再向下探寻。
        for(int i=pre+1; i<n ; i++){
            result.push_back(i+1);
            pre = i;
            dfs(list,result,n,k,pos+1,pre);
            result.pop_back();//回溯
        }
        return;
    }
};
```