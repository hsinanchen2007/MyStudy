### 解题思路
构建以得分为依据的大顶堆，堆中元素为pair<原下标, 得分>，不断从堆顶取出元素，前三个分配奖牌，后面的分配名次。
### 代码

```cpp
class Solution {
public:
    struct cmp{
        bool operator()(pair<int, int> a, pair<int, int> b){
            return (a.second < b.second) ? true : false;
        }
    };
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        int len = nums.size();
        vector<string> out(len);
        int i;
        pair<int, int> pa;

        for(i = 0; i < len; i++){   //构建大顶堆
            pa.first = i;
            pa.second = nums[i];
            q.push(pa);    
        }

        for(i = 0; i < len; i++){  //依次取出元素
            if(i > 2){             //名次先于奖牌分配，因为没有奖牌的选手数量大大多于有奖牌的选手数量，此举可减少if的判断次数
                out[q.top().first] = to_string(i+1);
                q.pop();
            }else if(i == 1){
                out[q.top().first] = "Silver Medal";
                q.pop();
            }else if(i == 2){
                out[q.top().first] = "Bronze Medal";
                q.pop();
            }else{
                out[q.top().first] = "Gold Medal";
                q.pop();
            }
        }

        return out;
        
    }
};
```