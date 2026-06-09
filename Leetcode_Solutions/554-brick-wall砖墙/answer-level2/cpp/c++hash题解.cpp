算出每一行缝的位置，然后存入hash表中，最后统计出缝的数字计数最大的值，wall.size()-这个值，就能得到穿过砖的最小数字
```
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> temp;
        for(int i=0;i<wall.size();++i)
        {
            int m=0;
            for(int j=0;j<wall[i].size()-1;++j)
            {
                m+=wall[i][j];
                if(temp[m])
                    temp[m]++;
                else temp[m]=1;
            }
        }
        int val=0;
        for(auto i=temp.begin();i!=temp.end();i++)
        {
            val=max(val,i->second);
        }
        return wall.size()-val;
    }
};
```
