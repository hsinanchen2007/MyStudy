
### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);
        int i=-1,n=0;
        while(1){
            i=(i+1)%num_people;
            n++;
            if(candies-n<0)//不够分这个人
                break;
            candies=candies-n;  
            ans[i]=ans[i]+n;
        }
        ans[i]=ans[i]+candies;
        return ans;
    }
};
```