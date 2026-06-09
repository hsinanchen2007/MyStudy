先对出生和死亡时间排序 时间复杂度o(log(n));
然后设置两个指针指向出生序列和死亡序列，出生时间<=死亡时间时，总人口+1，否则-1；
并且设置一个标记，记录总人口最大时的序列号。
```
class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int i=0,j=0,sum=0,max=0,flag=0;
        //for(auto d:death)d++;
        sort(birth.begin(),birth.end());
        sort(death.begin(),death.end());
        while(i<birth.size()){
            if(birth[i]<=death[j]){
                sum++;
                if(max<sum){
                    max=sum;
                    flag=i;
                }
                i++;
            }
            // else if(birth[i]==death[j]){
            //     i++;
            //     j++;
            // }
            else{
                j++;
                sum--;
            }
        }
        return birth[flag];
    }
};
```
