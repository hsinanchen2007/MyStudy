### 解题思路
本代码慢的一比，击败11.47%用户
思路就是遇到一个数num看看能不能单独并到前一个数num-1上，
再看看num+1所在的连续序列能不能再并起来，
每一个序列的根父节点都是目前该序列中最小的那一个元素。

### 代码

```cpp
class Solution {
public:
    int findfather(map<int, vector<int>> &father, int num)
    {
        if (father.count(num) > 0)
        {
            if (father[num][0] == 1) //儿子
            {
                //路径压缩
                return father[num][1] = findfather(father, father[num][1]);
            }
            else                //父亲
            {
                return num;
            }
        }
        return 0;//一般不会到这里吧，随便了
    }
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        
        map<int, vector<int>> father;   //father 0 or son 1
        for (auto num : nums)
        {
            if (father.count(num) > 0)
            {
                continue;
            }
            vector<int> status(2, 0);//status[0] 是表示num是father-0还是son-1，status[1]表示他的son数量+1或者他的父节点
            status[1] = 1;                  //1个son(自己) | 
            father[num] = status;
            maxlen = max(1, maxlen);        //目前有一个节点，
            int fn = num;                   //父节点是自己
            if (father.count(num - 1) > 0)  //前一个数num-1存在
            {
                fn = findfather(father, num - 1);   //找到前一个数的根父节点
                status[0] = 1;                      //当前节点改为儿子节点
                status[1] = fn;                     //[1]存根父节点
                father[num] = status;               //更新status
                father[fn][1]++;                    //根父节点所在的连续序列长度+1
            }
            if (father.count(num + 1) > 0)  //后一个数num+1存在
            {
                if (father[num + 1][0] == 0)//后一个是父节点
                {
                    father[fn][1] += father[num + 1][1];    //根父节点连接num+1所在的连续序列，长度相加
                    father[num + 1][0] = 1;         //改父子状态
                    father[num + 1][1] = fn;        //改故节点
                }
            }
            if (father[fn][1] > maxlen)
            {
                maxlen = father[fn][1]; //长度
            }
        }
        return maxlen;
    }
};
```