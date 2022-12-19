### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>v;
        v.resize(num_people);
        if(candies==0){
            return v;
        }
        int i=1;
        int people=0;
        while(candies>0){
            if(candies>i){
                if(people==num_people){
                    people=0;
                }
                v[people]=v[people]+i;
                candies-=i;
                i++;
                people++;
            }
            else{
                if(people==num_people){
                people=0;
                }
                v[people]+=candies;
                break;
            }
        }
        return v;

    }
};
```