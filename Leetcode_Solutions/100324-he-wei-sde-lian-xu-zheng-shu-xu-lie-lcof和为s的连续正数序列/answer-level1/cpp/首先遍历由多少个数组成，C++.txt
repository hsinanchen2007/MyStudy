这就是其它题解说的间隔法。
！符号优先级更高，被这个bug卡出了一会儿
```
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> result;
    vector<int> part;
    
    for(int i=target-1;i>1;i--){// 由i个数组成
        part.clear();
        if(i%2&&!(target%i)){
            int f=target/i-(i-1)/2;
            if(f<=0) continue;
            for(int j=0;j<i;j++){
                part.push_back(f++);
            }
            result.push_back(part);
        }
        else if(!(i%2)&&!(target*2%i)&&(target*2/i)%2){
            int f=target/i+1-i/2;
            if(f<=0) continue;
            for(int j=0;j<i;j++){
                part.push_back(f++);
            }
            result.push_back(part);
        }
    }
    return result;
    }
};
```
