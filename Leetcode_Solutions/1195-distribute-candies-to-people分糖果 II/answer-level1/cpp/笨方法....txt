### 解题思路
此处撰写解题思路
一个小白，一开始还不懂vector的用法...思路很简单，希望对和我一样的小白有帮助
### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>a(num_people, 0);
        int flag=0;//标志位，用于确定for循环的次数，每多一次循环就要多减去flag*num_people
        while(candies>0)//若candies小于零，跳出while循环
        {
            for(int i=1;i<=num_people;i++)
            {
                if(candies<(i+flag*num_people))//比较剩下糖果和这一次原本要发的糖果的多少
                {
                    a[i-1]+=candies;//+=,注意要把上次的a[i-1]也加进来
                }
                else
                {
                    a[i-1]+=i+flag*num_people;
                }
                candies-=(i+flag*num_people);//每次发完记得减去发的糖果
                if(candies<=0)//如果小于零，记得先跳出for循环
                {
                    break;
                }  
            }
            flag++;
        }
        return a;
    }

};
```