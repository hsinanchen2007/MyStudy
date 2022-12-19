首先将wall改写，改为统计每一个砖块到该行最左边的距离，比如[1,2,3]改写为[1,3,6]，第二步统计wall中出现的所有元素中个数最多的那个元素的个数，统计为max，这里实现的方法为使用map,遍历整个wall，以更新map，最终返回墙的高度减去max。
```
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        for(int i=0;i<wall.size();i++){
            for(int j=1;j<wall[i].size();j++){
                wall[i][j]+=wall[i][j-1];
            }
        }
        map<int,int>count;
        int max=0;
        for(int i=0;i<wall.size();i++){
            for(int j=0;j<wall[i].size()-1;j++){
                if(count.find(wall[i][j])!=count.end()){
                    count[wall[i][j]]++;
                }
                else{
                    count[wall[i][j]]=1;
                }

                max=max<count[wall[i][j]]?count[wall[i][j]]:max;
            }
        }
        return wall.size()-max;
    }
};
```
