![1586059821(1).jpg](https://pic.leetcode-cn.com/b9cecd39315bded72a713e192515163af2d5af350fa9e5ee864527dd8d1b971c-1586059821\(1\).jpg)

欢迎提出宝贵意见。

```
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int,int> map1;
        vector<int> vec,vec2;
        vector<vector<int>> vec1;
        int tmp;
        for(int i=0;i<points.size();i++){
            vec.clear();
            map1.clear();
            for(int j=0;j<points.size();j++){
                tmp=(points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                if(map1[tmp]==0) vec.push_back(tmp);
                map1[tmp]+=1;
            }
            vec2.clear();
            for(int j=0;j<vec.size();j++){
                if(map1[vec[j]]>=2) vec2.push_back(map1[vec[j]]);
            }
            vec1.push_back(vec2);
        }
        int sum_=0;
        for(int i=0;i<vec1.size();i++){
            for(int j=0;j<vec1[i].size();j++){
                sum_=sum_+vec1[i][j]*(vec1[i][j]-1)/2;
            }
        }
        return 2*sum_;
    }
};
```

