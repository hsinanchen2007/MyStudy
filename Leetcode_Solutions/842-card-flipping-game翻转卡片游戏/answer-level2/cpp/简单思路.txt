```
//这个题的思路可以很简单，如果某个背面的数n是解，那么背面和这个数相等的数不用考虑，只需要考虑正面相等的即可。
//正面为n的数必须都可以被替换为不为n的数，也就是说不存在正反相等的情况
//由于正反是对称的，所以只需要找到不存在上述情况的最小数即可
class Solution {
public:
    int res;
    bool vis[2001];//判断这个数是否可能为候选结果
    set<int> list;
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        for(int i=0;i<fronts.size();i++) {
            if(fronts[i]==backs[i]) vis[fronts[i]] = true;//正反相等时这个数不可能是结果
            list.insert(fronts[i]);list.insert(backs[i]);
        }
        for(auto& it: list) if(!vis[it]) {res=it;break;}//从最小的数开始找，知道出现候选结果结束
        return res;
    }
};
```
