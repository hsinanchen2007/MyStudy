### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
int max_num = 40000;
int accumulate(int num){
    int ret = 0;
    for(int i=0;i<=num;i++){
        ret+=i;
    }
    return ret;
}
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() == 0)
        return 0;
        int mymap[40001]={0};
        int ret = 0;
        for(auto it:A){
            mymap[it]++;
        }
        for(int i=0;i<max_num;i++){
            int add = (mymap[i] - 1)>0?mymap[i]-1:0;;
            ret+=add;
            mymap[i+1] += add;
        }
        if(mymap[max_num] > 1){
            ret+=accumulate(mymap[max_num]-1);
        }

        /*for(auto it:mymap){
            ret+=(int)(it.second) - 1;
            mymap[(int)(it.first)+1] +=(int)it.second-1;
        }*/
        return ret;


    }
};
```