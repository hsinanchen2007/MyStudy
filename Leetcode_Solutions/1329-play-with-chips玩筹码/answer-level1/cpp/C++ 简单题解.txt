![image.png](https://pic.leetcode-cn.com/5d15fc8a27409c75c0fac6eec030eb90fd9f71d578735f2bda0bb77a459d71db-image.png)
解题思路：由于移动两个步长不需要代价，所以奇数与奇数、偶数与偶数之间的转化不需要代价，只需要把所有的奇数、偶数移动到相邻位置，再把较少的移到对面即可。
```
    int minCostToMoveChips(vector<int>& chips) {
        vector<int> oddvec = {};
        vector<int> evevec = {};
        for(auto itm : chips){
            if(itm%2 == 0) evevec.push_back(itm);
               else oddvec.push_back(itm);
        }
          return min(evevec.size(),oddvec.size());
    }
```
