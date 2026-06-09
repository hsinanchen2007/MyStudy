### 如果哪里写的不好、不对,欢迎指正！一定虚心接纳
**主要思想**：遍历所有的点，找到所有可能的组合。对于遍历的每个点，将其视为**起点**，在起点固定的情况下，此时仅需要考虑斜率。斜率作为hashmap的key，同样斜率的直线作为hashmap的value；

**注意事项**：（1）斜率有水平、垂直之分，必须要考虑到特殊情况；（2）可能会有重复的点，如何处理重复的点？（3）**斜率的精度**一定要有保证。例如：(0,0)->(1000000001,1000000002) 和(0,0)->(1000000000,1000000002)两条直线，在C++中可能斜率都被视为1，而实际上斜率是不同的。

**代码**：
```c
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.empty()){
            return 0;
        }
        if(points.size()==1){
            return 1;
        }
        unordered_map<double, int> line;
        double slope(0.0);
        int max(0),tmp_max(0), addtional(0);
        for(vector<int> s:points){
            line.clear();
            tmp_max = 0;
            addtional = 0;
            for(vector<int> e:points){
                if(e==s){
                    addtional++;
                }else{
                    if(e[0]-s[0]==0){
                    slope = INT_MAX;
                    }else{
                        slope = (double)(e[1]-s[1])*1000000000000.0/(double)(e[0]-s[0]);
                    }//这一步很重要，否则相似的斜率会被视为相等的斜率，导致结果偏大。
                    line[slope]++;
                    if(line[slope]>tmp_max){
                        tmp_max = line[slope];
                    }
                }
            }
            max = tmp_max + addtional > max?tmp_max+addtional:max;
        }
        return max;
    }
};
```
