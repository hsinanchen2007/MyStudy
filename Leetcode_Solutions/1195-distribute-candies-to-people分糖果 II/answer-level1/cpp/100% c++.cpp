```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int tmp=0,sum=0;
        vector<int> res(num_people,0);
        while(true){
            for(int j=0;j<num_people;++j){
                ++tmp;
                sum+=tmp;
                if(sum>candies){
                    res[j]+=(candies-sum+tmp);
                    return res;
                }
                res[j]+=tmp;
            }
        }
        return res;
    }
};
```