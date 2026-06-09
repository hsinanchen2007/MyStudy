![image.png](https://pic.leetcode-cn.com/30218bf7f86df6975eb88a0f324e4a5dd9246e7b18a731a6b4d169c8b660cd71-image.png)
解题思路：x、y分别从1、1000开始计算，结束条件为想x<=1000,y>=1,将满足条件的整数对存入二维数组res并返回。
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
         vector<vector<int>> res = {};
         int x =1; int y = 1000;
         while(x<=1000 && y>=1 ){
            if(customfunction.f(x,y) == z) {
               res.push_back({x,y});
               ++x;--y;
            }
            else if(customfunction.f(x,y)<z){
                ++x;
            } else --y;
        }
        return res;
    }