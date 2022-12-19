### 解题思路
我们假设从头到尾完全分配一次成为完整分配,接下来就有三个步骤：
1.计算完整分配的次数;
2.将能完整分配的进行分配;
3.再将不能完整分配的进行分配;
其实后面两步可以合成一步的，这里留给有余力的去做吧。
### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        vector<int> vec;
        vec.push_back(0);
        int i=0,n=num_people;
        for(i=1;;i++)
        {//计算前多少次完整分配可以被满足
            int num=(i*n+(i-1)*n+1)*n/2;
            vec.push_back(vec[i-1]+num);
            if(vec[i-1]<=candies && vec[i]>candies)
                break;
        }
        int c=i-1;
        if(c!=0)
        {//把完整分配的结果先装上
            int num=0;
            for(i=0;i<n;i++)
            {
                num=((c-1)*n+(i+1)*2)*c/2;
                ans[i]=num;
            }
            candies-=vec[c];
        }
        i=0;
        while(candies>0)
        {//再把不完整的分配给分配下
            int num=c*n+(i+1);
            if(candies>=num)
            {
                ans[i]=ans[i]+num;
                candies-=num;
            }
            else
            {
                ans[i]=ans[i]+candies;
                break;
            }
            i++;
        }
        return ans;
    }
};
```