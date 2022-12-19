### 解题思路
数学公式法，O(1)复杂度
太菜了，推数学公式推错了俩次！
太菜了，取模整除忘记从1开始时时1，2，3...0了，应该减1再加mod再取模（避免负数取模）
### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        double n = ( double )num_people; 
        int lastNeedGive = ceil( (-1 + sqrt(1+8*1.0*(double)candies ) )/2.0  );
        int nowIsRound = (lastNeedGive-1)/num_people;
        int nowIsPeopleNum =   (lastNeedGive - 1 + num_people) % num_people +1 ;
        //cout<<lastNeedGive<<" "<<nowIsRound<<" "<<nowIsPeopleNum;
        vector<int> ans;
        int i=1;
        int yu = candies - (1 + nowIsRound*num_people)*nowIsRound*num_people/2;
        while (i<=num_people){
            int nowNeedGive = nowIsRound*num_people + i;
            if (yu >= nowNeedGive){
                ans.push_back( (i+ nowNeedGive)*(nowIsRound+1)/2  );
                yu-=nowNeedGive;
            }else{
                ans.push_back( (i+ nowNeedGive)*(nowIsRound+1)/2 - (nowNeedGive-yu)  );
                yu = 0;
            }
            i++;
        }
        return ans;
    }
};
```