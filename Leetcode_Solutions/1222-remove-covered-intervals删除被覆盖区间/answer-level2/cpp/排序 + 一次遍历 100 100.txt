### 解题思路
思路非常简单：
            1. 对每一个范围[low, high] 的low进行排序
            2. 然后，每一个新的范围都必须是 newHigh > oldHigh 否则被覆盖（newHigh <= oldHigh）
              
            这很容易理解： 一位前面low 已经排过序了， 所以必有： newLow >= oldLow
            再加上 2. 的 newHigh <= oldHigh 
            就达成了 覆盖 的条件
以为只需直到最后的个数，所以不需要取操作 vector ，sum -- 即可


时间复杂度： O（nlgN） 主要是排序花费，后面只需一次遍历
空间复杂度： 还是排序的花费O（1） （应该没记错吧？ 错了提醒我）

### 代码

```cpp
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int> >::iterator p = intervals.begin();

        int last = (*p)[1];
        p ++;
        int sum = intervals.size();
        while (p != intervals.end()){
            if ((*p)[1] <= last ){
                sum --;
            }
            else{
                last = (*p)[1];
            }
            p ++;
        }

        return sum;
    }

    bool compare(vector<int> &A, vector<int> &B ){
        return A[0] < B[0] ? true : false;
    }
};
```