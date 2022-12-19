### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private: vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        int label = s.size()-1;
        int points = 3;
        helpFunction(s,points,label);
        return res;
    }
    void helpFunction(string s,int points,int label){
        // points 是当前未插入的点数，label是从后往前，当前开始考虑插入的位置，考虑在label label-1，label-2 三个位置插入点。
        // 返回规则 points 用完，检查s.substr(0,label+1) 部分是否满足要求，如果满足，放入结果中。
        if(points==0){
            int k = stoi(s.substr(0,label+1));
            // 既要保证不大于255，也要保证不会以0开头（0）除外。
            if((to_string(k).size()==label+1)&&(k<=255)) res.push_back(s);
        }
        // points没用完，考虑在label label-1,label-2 三个位置插入点
        else{
            for(int i=0;i<3;i++){
                if(label-i<=0) continue; // 保证不越界，点不能在开始位置插入，故0也不行
                else{
                    if(label-i-1+1>(points-1+1)*3) continue;// 剪枝，如果把点设置在这个位置，前面的长度超出最大范围，减掉。
                    int k = stoi(s.substr(label-i,i+1));
                    if((to_string(k).size()==i+1)&&(k<=255)){
                        s.insert(label-i,".");
                        helpFunction(s,points-1,label-i-1);
                        s.replace(label-i,1,"");
                    }
                }
            }
        }
    }
};
```