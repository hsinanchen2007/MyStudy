```
class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        vector<int> res;
        //找大的
        int cnt_1=0,i=0;
        while(i<32 and ((num&(1<<i))==0)){//跳过所有后缀0
            ++i;
        }
        if(i>=32){
            i=0;
        }
        while(i<32 and (num&(1<<i))){//找第一个xxxx01xxx
            ++i;
            ++cnt_1;
        }
        if(i>=32){
            res.push_back(-1);
        }
        else{
            int res1=num;
            res1|=(1<<i);//变成xxxx10xxx
            res1^=(1<<(i-1));
            int j=0;
            for(;j<cnt_1-1;++j){//后缀的所有1都放到最后面，比如之前01  10110100-》10  00001111，左边空的位补0
                res1|=(1<<j);
            }
            while(j<(i-1)){
                if(res1&(1<<j)){
                    res1^=(1<<j);
                }
                ++j;
            }
            res.push_back(res1);
        }
        //找小的
        i=1,cnt_1=0;
        while(i<32){
            if((num&(1<<i)) and (num&(1<<(i-1)))==0){//从右找第一个xxx10xxx
                break;
            }
            if(num&(1<<(i-1))){
                cnt_1++;
            }
            ++i;
        }
        if(i>=32){
            res.push_back(-1);
        }
        else{
            num^=(1<<i);//xxxx10xxx改成xxxx01xxx
            num|=(1<<(i-1));
            int j=0;
            for(;j<cnt_1;++j){//后缀的1都放到左边，比如之前10  001101101-》01  111110000，右边空的位补0
                num|=(1<<(i-2-j));
            }
            while(i-2-j>=0){
                if(num&(1<<(i-2-j))){
                    num^=(1<<(i-2-j));
                }
                j++;
            }
            res.push_back(num);
        }
        return res;
    }
};
```
