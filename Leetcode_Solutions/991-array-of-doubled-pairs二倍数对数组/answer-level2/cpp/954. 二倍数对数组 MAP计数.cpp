### 解题思路
本以为是个青铜，结果是个王者，需要考虑的细节真的很多
核心思想：
1）按绝对值从小到大排序；
2）如果满足条件的组合存在，那么。当x存在时，一定存在2x；因此我们可以对所有数字进行统计；
（请注意：**关键点 x和2x的次数可能是不相等的，比如 1,2,2,4 ，是满足条件的，**但是1和2,2和4的次数是不相等的，因此不能通过直接比较map中x和2x的计数来确定是否满足条件。）
3）对数字依次遍历，每次对x和2x减1，对count计数+2；如果count==size，则返回为真，否则为false；

没想到啊，最暴力的方法最有效

### 代码

```cpp
class Solution {
public:
    static bool myfun(int a, int b)
    {
        if (abs(a) < abs(b)) {
            return true;
        } else if (abs(a) == abs(b)) {
            if (a< b ){
                return true;
            }
        }

        return false;
    }
    bool canReorderDoubled(vector<int> &A)
    {
        unordered_map<int, int> numcount;
        for (auto a : A) {
            numcount[a]++;
        }
        sort(A.begin(), A.end(), myfun);
        int count = 0;
        for(auto a:A){
            if(numcount.count(a) && numcount[a] != 0){
                numcount[a]--;
                numcount[2 * a]--;
                count += 2;
            }
        }

        if(count == A.size()){
            return true;
        }
        return false;
    }
};
```