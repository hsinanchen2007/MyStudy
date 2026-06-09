# ***纯数学问题***
```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        //求出最多能达到第几个糖果,由1,2,3,n相加,即candies=(num+1)*num/2,num=(-1+sqrt(1+8*candies))/2;
        int num = (-1+sqrt(1+(long)8*candies))/2;
        //求出剩余的糖果,总糖果数-第num个糖果数之和,surplus=candies-(num*(num+1)/2)
        int surplus = candies - (num*(num+1)/2);
        //求出最大循环次数,遍历到num,每次循环num_people,times=num/num_people
        int times = num / num_people;
        //输出数组
        vector<int>res(num_people);
        for(int i = 0; i < num_people; i++){
            //以第一个小朋友为例,第一次获得1个糖果,第二次num_people+1,第三次2*num_people+1
            //所以第times次,总共有times个1,有(times-1)*times个num_people
            //第i个,因为i从0开始,所以总共有times个i+1,有(times-1)*times个num_people
            //num-times*num_people为最后剩下的未满一个周期的个数k,说明1~k多一次循环,而第k+1要加上剩余糖果数surplus

            if(i+1  <= num - times * num_people)
                res[i] = (i+1)*(times+1)+num_people*(times)*(times+1)/2;
            else{
                res[i] = (i+1)*times+num_people*(times-1)*(times)/2+surplus;
                surplus = 0;
            }
        }
        return res;
    }
};
```

赋个没注释的,看的清楚一些
```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int num = (-1+sqrt(1+(long)8*candies))/2;
        int surplus = candies - (num*(num+1)/2);
        int times = num / num_people;
        int surplus1 = num - times * num_people;
        int flag = 0;
        vector<int>res(num_people);
        for(int i = 0; i < num_people; i++){
            int k = i + 1 <= surplus1 ? times + 1 : (flag = surplus, surplus = 0, times);
            res[i] = (i+1)*k+num_people*(k-1)*k/2+flag;
        }
        return res;
    }
};
```

# 时间复杂度:O(n)
# 空间复杂度:O(n)