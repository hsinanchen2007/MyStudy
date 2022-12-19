感觉像是一道数学题。
我的思路是先判断要分几遍，然后再分

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> v(num_people, 0);
        int num = 1;
        //int sum = (num_people+1)*num_people/2;
        int people = num_people;
        int sum = (people+1)*people/2;
        while(candies > sum)
        {
            num++;
            people = num_people*num;
            sum = (people+1)*people/2;
        }
        cout << "num" << num <<endl;
        for(int i = 0; i < num; i++)
        {
            for(int j = 0; j < num_people; j++)
            {
                int candy =  (i*num_people + 1 + j);
                if(candies > candy)
                {
                    candies = candies - candy;
                    v[j] = v[j] + candy;
                }
                else
                {
                    v[j] = v[j] + candies;
                    break;
                }
                //cout << "i" << i << "j" << j << "candy:" <<candy << "candies:" <<candies <<endl;
                //cout << "candies:" <<candies << endl;
                
            }
        }
        return v;
    }
};
```