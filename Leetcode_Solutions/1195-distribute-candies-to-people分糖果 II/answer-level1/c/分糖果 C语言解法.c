### 解题思路
1.为了减少赋值和循环次数，先计算出发的轮数
2.考虑三种情况
(1)刚好发满整轮结束
(2)最后一轮刚好发满一个人结束
(3)最后一轮未发满最后一人结束


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int times = 1, candies_cur = (1+num_people)*num_people/2;
    int *ans = (int*)(malloc(num_people*sizeof(int)));
    while(candies > candies_cur){ //获取循环发糖的次数
        candies -= candies_cur;
        candies_cur = (1+(2*times+1)*num_people)*num_people/2;
        if(candies!=0) times++;
    } // 循环完毕   candies为最后一轮需要发出的糖果,times为循环发糖的轮数
    int i = 1;
    int trag = candies==0? 1:2;
    candies_cur = i+(times-1)*num_people;
    while(candies>candies_cur){ //发满times轮的人
        ans[i-1] = ((i+candies_cur)*times/2);  
        candies -=candies_cur;
        candies_cur = ++i + (times-1)*num_people;
    }
    if(candies!=0){ //最后一人有余粮但不满
        ans[i-1] = (2*i+((times-2)<0?0:(times-2))*num_people)*(times-1)/2 + candies;
        i++;
    }
    while(i-1<num_people){ //发了times-1轮的人
        ans[i-1] = times==1?0:((2*i+(times-trag)*num_people)*(times-1)/2) ;i++;
    }
    *returnSize = num_people;
    return ans;
}
```