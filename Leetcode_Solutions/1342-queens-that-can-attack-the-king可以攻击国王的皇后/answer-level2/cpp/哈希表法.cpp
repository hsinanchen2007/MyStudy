思路：
1.将所有【黑皇后】记录在set表中;（unordered_set不能用不知道为何，求指教）
2.【白国王】从8个方向出发：用next_数组存储8个方向
3.每个方向每走一步，就检测一下set表中是否存在，如果存在则直接将当前位置进行存储且该方向不再移动

注：萌新写注释，有错误欢迎指出QAQ,对了该方法应该还能优化，只不过我懒得改了2333
```
class Solution {
public:
    int next_[8][2]={
        {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
    };
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<pair<int, int>> s;
        vector<vector<int>> res;
        for(auto&queen:queens) s.insert(make_pair(queen[0],queen[1]));
        for(int i=0;i<8;i++){
            int r=king[0]+next_[i][0],c=king[1]+next_[i][1];
            while(r>=0&&r<8&&c>=0&&c<8&&s.find(make_pair(r,c))==s.end()){
                r=r+next_[i][0],c=c+next_[i][1];
            }
            if(r>=0&&r<8&&c>=0&&c<8){
                vector<int> v;
                v.push_back(r);
                v.push_back(c);
                res.push_back(v);
            }
        }
        return res;
    }
};
```
