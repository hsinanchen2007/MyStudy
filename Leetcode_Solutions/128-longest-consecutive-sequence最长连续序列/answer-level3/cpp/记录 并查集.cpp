### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    unordered_map<int, int> uf, cnt;
    int longestConsecutive(vector<int>& nums) {
        int maxL = 1;
        if(nums.size() == 0)
            return 0;
        
        for(int i : nums){ 
            uf[i] = i;
            cnt[i] = 1;
        }
        for(int i : nums){
            if(uf.count(i+1)){
                int res = merge(i, i+1);
                maxL = max(maxL, res); 
            }
        }
        return maxL;
    }

    int merge(int i, int j){
        int x = find(i), y = find(j); //找到i和j的根节点
        if(x == y) { //如果属于同一集合
            return cnt[x]; //返回该集合的节点数
        }
        uf[y] = x;//如果不属于同一集合，将j的根节点y设为x的子节点，表示i，j属于同一集合，此时由原本的根节点y变为x的子节点，
                    //那么j的父节点不是根节点，在find的时，如果不做处理，会增加搜索的时间，因此在find的时，将每个点的父节点都设为根节点
        cnt[x] += cnt[y]; // 根节点的cnt值表示，该集合节点数，合并时相加
        return cnt[x];
    }

    int find(int i){ //返回根节点，根节点相同表示在同一集合
        if(i == uf[i]) //如果为根节点
            return i;   //直接返回
        uf[i] = find(uf[i]); //如果不是根节点，将它的父节点设为根节点，避免通过while循环找根节点
        return uf[i]; //返回根节点
    }

};
```