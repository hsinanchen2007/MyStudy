### 解题思路
模拟完成过程
### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);int count = 0;
        while(candies>0)
        {
            
            if(candies>count)
            {
                res[count%num_people]  = res[count%num_people]+count+1;
            }
            else
            {
                res[count%num_people]  = res[count%num_people]+candies;
            }
            count++;
            candies-=count;
            // cout<<"candies: "<<candies<<endl;
            // for(int i = 0;i<num_people;i++)
            // {
            //     cout<<res[i]<<" ";
            // }
            // cout<<endl<<"---------------"<<endl;
        }
        return res;
    }
    
};
```