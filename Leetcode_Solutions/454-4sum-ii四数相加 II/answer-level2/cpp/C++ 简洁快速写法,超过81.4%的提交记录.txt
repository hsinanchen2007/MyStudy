```
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        //key是当前值,value是当前值被找到的次数
        unordered_map<int,int> rec;
        int ret = 0;
        for(auto a  : A){
            for(auto b : B){
                rec[a+b]++;
            }
        }
        for(auto c  : C){
            for(auto d : D){
                //如果找到了,就说明这两组数之和可以与之前两组组合
                if(rec.find(-c-d)!=rec.end())
                    ret+=rec[-c-d];
            }
        }
        return ret;
    }
};
```
