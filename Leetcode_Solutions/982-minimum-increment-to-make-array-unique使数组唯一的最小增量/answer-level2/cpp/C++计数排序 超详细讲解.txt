### 解题思路
写在代码里
### 代码

```cpp

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int size = (int)A.size();
        if (size <= 1) return 0;
        // counts统计每个数字的个数。
        // 官方题解 复杂度太高 只要记录最大值  下面遍历可以直接遍历到max
        vector<int>counts(40001,0);
        int rs = 0;
        int max_ = -1;
        for (int num: A) {
            counts[num]++;
            max_ = max(max_, num);
        }
        //0 1 2 3 4 5 6 7
        //0 2 2 1 0 0 0 1
        for (int i = 0; i <= max_; i++) {
            if(counts[i] <= 1) continue;
            //1 出现了2次 需要将1一个1 变成2
            int rest = counts[i] - 1;
            //将1一个1 变成2 那么2的个数加1
            counts[i+1] += rest;
            //1个1 变成1个2  总共需要1步
            rs += rest;
            //0 1 2 3 4 5 6 7
            //0 2 3 1 0 0 0 1
            //2 出现了3次 需要将2个2变成3 3的个数加2
            //0 1 2 3 4 5 6 7
            //0 2 3 3 0 0 0 1
            //以此类推  最后
            //0 1 2 3 4 5 6 7
            //0 2 3 3 2 1 0 1
        }
        
        //特殊处理  如果counts[max] > 1说明最后一个 还是多了
        //0 1 2
        //0 1 4
        //0 1 4 3 2 1
        //4个2      多了3个2  3个2变成3个3  上面的循环这个3已经加过了
        //然后3个3   多了2个3 2个3变成2个4
        //让2个4     多了1个4 1个4变成1个5
        //这时候 counts[max_+1] = 3（上面的循环这个3已经加过了）
        //所有最后只要 1 + 2 + 3 +....counts[max_+1] -1
        int rest = counts[max_+1] - 1;
        rs += rest * (rest + 1) / 2;
        return rs;
    }
};
```