### 解题思路
![TIM截图20200314163258.png](https://pic.leetcode-cn.com/44abd8a1e5bfac95693961228ded3d967391260b290df9bdd8bc0119c0f128e2-TIM%E6%88%AA%E5%9B%BE20200314163258.png)
为每个演员建立一个pair<height, weight>，按照height从小到大的顺序排列，如果遇到多个height相同的演员则按照weight从大到小顺序排列（后续找weight增序列的时候防止选到height相同的演员）。
排列完成后，序列中演员的height都是从小到大，现在只需找出在此序列中weight也从小到大的最长子序列即可满足要求。
找最长递增子序列算法见注释，部分代码借鉴了其他答主的解答。
### 代码

```cpp
class Solution {
public:
    struct cmp{
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            if(a.first < b.first) return true;
            else if(a.first == b.first) return (a.second > b.second) ? true : false;
            else return false;
        }
    };

    int max(int a, int b){
        return (a > b) ? a : b;
    }

    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        int len = weight.size();
        if(len == 0) return 0;
        vector<pair<int, int>> guys;
        pair<int, int> temp(0, 0); //first is height, second is weight
        int i, j;
        int max_num = 0;
        for(i = 0; i < len; i++){
            temp.first = height[i];
            temp.second = weight[i];
            guys.push_back(temp);
        }

        sort(guys.begin(), guys.end(), cmp());

        vector<int> up;              //up[k]的值是长度为k+1的递增子序列的最后一个演员的weight
        up.push_back(guys[0].second);       //最开始长度为1的递增子序列只有第0个元素
        for(i = 1; i < len; i++){      
            if(guys[i].second > up.back()){      //若第i个元素的weight大于目前最长递增子序列的最后一个元素的weight
                up.push_back(guys[i].second);    //则目前最长递增子序列长度加一，序列尾元素为第i个演员
            }else{
                auto pos = lower_bound(up.begin(), up.end(), guys[i].second);  //否则找出up中大于第i个演员的最小的元素，
                *pos = guys[i].second;                                         //将其更新为第i个演员
            }
        }
        return up.size();
    }
};
```