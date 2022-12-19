每一个人都选择最优选择，有3种选择，选择最优的，不断的枚举。
记录历史结果：由于两个选手是对称的，同样的开始位置都是相同的结果。

```
class Solution {
public:
    int n;
    int record[2];
    int cache[50005][2];

    void select(const vector<int>& stoneValue ,int start,int mode){
        if(start>=n){
            return;
        }
        int other_mode=mode==0?1:0;

        if(cache[start][0]!=-1 && cache[start][1]!=-1){
            record[mode]=cache[start][0];
            record[other_mode]=cache[start][1];
            return;
        }

        
        
        if(n-start==1){
            record[mode]+=stoneValue[start];
        }
        else if(n-start==2){

            record[mode]+=stoneValue[start];
            if(stoneValue[start+1]>0){
                record[mode]+=stoneValue[start+1];
            }
            else{
                record[other_mode]+=stoneValue[start+1];
            }
        }
        else if(n-start>=3){

            int best_diff=-INT_MAX;
            int best_record[2];
            
            record[0]=record[1]=0;
            select(stoneValue,start+1,other_mode);
            record[mode]+=stoneValue[start];
            if(record[mode]-record[other_mode]>best_diff){
                best_diff=record[mode]-record[other_mode];
                best_record[0]=record[0];
                best_record[1]=record[1];
            }

            
            record[0]=record[1]=0;
            select(stoneValue,start+2,other_mode);
            record[mode]+=stoneValue[start];
            record[mode]+=stoneValue[start+1];

            if(record[mode]-record[other_mode]>best_diff){
                best_diff=record[mode]-record[other_mode];
                best_record[0]=record[0];
                best_record[1]=record[1];
            }

            record[0]=record[1]=0;
            select(stoneValue,start+3,other_mode);
            record[mode]+=stoneValue[start];
            record[mode]+=stoneValue[start+1];
            record[mode]+=stoneValue[start+2];
            if(record[mode]-record[other_mode]>best_diff){
                best_diff=record[mode]-record[other_mode];
                best_record[0]=record[0];
                best_record[1]=record[1];
            }

            record[0]=best_record[0];
            record[1]=best_record[1];
            
        }
        
        
        cache[start][0]=record[mode];
        cache[start][1]=record[other_mode];
        
    }

    string stoneGameIII(vector<int>& stoneValue) {
        memset(cache,-1,sizeof(cache));
        n=stoneValue.size();
        
        record[0]=record[1]=0;
        select(stoneValue,0,0);

        if(record[0]>record[1])
            return "Alice";
        else if(record[0]<record[1])
            return "Bob";
        else
            return "Tie";
    }
};
```
