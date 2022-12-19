### 方法一：暴力枚举
- 思路：
  - 暴力遍历查找，上界是target/2
- 时间复杂度：
  - o(n*sqrt(n))
- 空间复杂度：
  - o(1)
- 结果:
  - 用时：5%（560ms）
  - 内存：100%
```
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        for(int i=1;i<=target/2;i++){
            int sum=0,j;
            vector<int> tmp;
            for(j=i;sum<target;j++) sum+=j,tmp.push_back(j);
            if(sum==target) res.push_back(tmp);
        }
        return res;
    }
};
```

### 方法二：数学方法
- 思路：
  - 应用求根公式
- 时间复杂度：
  - o(n)
- 空间复杂度：
  - o(1)
- 结果:
  - 用时：54%（8ms）
  - 内存：100%
```
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        for(long i=1;i<=target/2;i++){
            long delta=1-4*i+4*i*i+8*target;
            if(delta>0){
                long sq=(long)sqrt((float)delta);
                if(sq*sq==delta && (sq-1)%2==0){
                    vector<int> tmp;
                    for(int j=i;j<=(sq-1)/2;j++) tmp.push_back(j);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};
```