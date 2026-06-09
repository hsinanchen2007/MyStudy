### 解题思路
见代码注释

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> p(num_people,0);
        //临界条件
        if(!(candies>=1&&candies<=pow(10,9)&&num_people>=1&&num_people<=1000))
            return p;
        int idea=1;
        for(int i=0;;i++)
        {
            //发完一轮
            if(i==p.size())
            {
                i=0;
            }
            //当剩余的糖果不够时
            if(candies<idea)
            {
                p[i]=p[i]+candies;
                break;
            }
            //当前小朋友的糖果数累加           
            p[i]=p[i]+idea;
            //剩余的糖果
            candies=candies-idea;
            // std::cout<<"i: "<<i<<endl;
            // std::cout<<"p: "<<p[i]<<endl;
            // std::cout<<"idea: "<<idea<<endl;
            // std::cout<<"candies: "<<candies<<endl;
            // std::cout<<"................."<<endl;
            //下一位小朋友应发的糖果数            
            idea++;

        }
        return p;

    }
};
```