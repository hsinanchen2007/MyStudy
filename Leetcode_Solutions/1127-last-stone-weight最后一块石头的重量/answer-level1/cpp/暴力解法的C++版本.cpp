```c++
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(),stones.end(), greater<int>());//每次循环后排一次序，greater是从大到小的规则参数
            if(stones[0]==stones[1]){
                stones.erase(stones.begin(),stones.begin()+2);//起始位置和终止位置的后一位
            }
            else{
                stones.push_back(stones[0]-stones[1]);//添加新的质量石头到最后
                stones.erase(stones.begin(),stones.begin()+2);
            }
        }
        if(stones.size()==0) return 0;
        else return stones[0];
    }
};

```
