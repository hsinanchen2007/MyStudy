时间复杂度O(1)
空间复杂度O(n)
```
class Solution {
public:
    int candy(vector<int>& ratings) {
        // 由题意可知，评分相等的孩子，拿到的糖果不一定必须一样
        // 只有评分高的，才会比相邻的低的多拿一颗
        int n = ratings.size();
        vector<int> candy(n, 1);
        if(n < 1){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        // 至少有2个孩子
        // 先正向遍历一遍，除了更新0号元素时考虑其后面的一个元素
        // 其余元素更新时，考虑如果大于前面一个的元素，自身的值就要在前面小朋友的基础上+1
        for(int i=0;i<ratings.size();i++){
            if(i==0){
                if(ratings[i] > ratings[i+1]){
                    candy[i] = candy[i] + 1;
                    continue;
                }
            }else{
                if(ratings[i] > ratings[i-1]){
                    candy[i] = candy[i-1] + 1;
                }
            }
        }
        // 仅仅正向遍历，如果遇到[1,3,2,1]这样的情况
        // 正向遍历结束，candey：[1,2,1,1]，发现如果后面的小朋友评分低于自己，却得到的是和自己一样
        // 因为在更新自己的时候，仅考虑了前面的小朋友
        // 于是再次反向遍历，考虑如果评分高于后面的小朋友却得分比后面的小朋友少或者一样
        // 为什么不是和后面的小朋友一样，因为第一遍遍历结束确实是和后面小朋友一样的
        // 但是，在反向更新之后，后面的小朋友可能也更新的了，那么现在自己的值就可能小于后面的小朋友了
        // 例子：[1,2,87,87,87,2,1]
        // 要更新自己的值，这样就得到了正确的candy：[1,3,2,1]
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1] && candy[i] <= candy[i+1]){
                candy[i] = candy[i+1] + 1;
            }
        }

        n = 0;
        for(int i=0;i<candy.size();i++){
            n += candy[i];
        }
        return n;
    }
};
```