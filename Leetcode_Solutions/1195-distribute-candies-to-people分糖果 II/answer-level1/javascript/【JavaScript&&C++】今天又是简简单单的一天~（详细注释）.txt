**没有那么多花里胡哨的技巧，今天又是简单单的一天~**


```javascript []
var distributeCandies = function(candies, num_people) {
    //保存答案的数组
    let res = [];
    //让数组的每一项初始值都为0
    for(let i = 0;i<num_people;i++)
    {
        res[i] =0;
    }
    //tmp代表当前这个孩子需要的糖果数
    let tmp = 1;
    //从数组的下标0（也就是第一个孩子）开始哦！
    let j = 0
    //当糖果能满足我面前的这个孩子的时候
    while(candies >= tmp)
    {
    //糖果变少了~因为分出去了...
       candies-=tmp;
    //这个孩子现在拥有的糖果 = 原来得到的+这一轮得到的
       res[j] +=tmp;
    //下一个孩子表示不服，想吃更多
       tmp++;
    //轮到下一个孩子啦，别着急哦！
       j++;
    //这一圈都发完啦，重新开始
       if(j > num_people-1) j = 0;
    }
    //走到你面前了，但是这次糖果比较少，算了全给你吧，哪怕是0个也给你
    res[j] +=candies;
    //返回最终答案
    return res;
};
```
```C++ []
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
            //保存答案的vector,让每一项初始值都为0
            vector<int> res(num_people,0);
            //tmp代表当前这个孩子需要的糖果数
            int tmp = 1;
            //从数组的下标0（也就是第一个孩子）开始哦！
            int j = 0;
            //当糖果能满足我面前的这个孩子的时候
            while(candies >= tmp)
            {
               //糖果变少了~因为分出去了...
               candies-=tmp;
               //这个孩子现在拥有的糖果 = 原来得到的+这一轮得到的
               res[j] +=tmp;
               //下一个孩子表示不服，想吃更多
               tmp++;
               //轮到下一个孩子啦，别着急哦！
               j++;
               //这一圈都发完啦，重新开始
               if(j > num_people-1) j = 0;
            }
            //走到你面前了，但是这次糖果比较少，算了全给你吧，哪怕是0个也给你
            res[j] +=candies;
            return res;
    }
};
```
