### 解题思路
map

### 代码

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len=T.size();
        vector<int> res(len);
        vector<vector<int>> t2d(101);            //温度 to 天数,每个温度维护一个天数数组
        int today;
        for(int i=0;i<len;i++){
            today=T[i];                    //今天的温度
            for(int j=30;j<today;j++){     //比今天低的所有温度都被拉出来判断一遍
                if(t2d[j].size()!=0) { 
                    for(int k=0;k<t2d[j].size();k++){
                        res[t2d[j][k]]=i-t2d[j][k];  //修改低的那一天的数值
                    }    
                    t2d[j].clear();     
                } 
            }
            t2d[today].push_back(i);   
        }
        return res;
    }
};
```