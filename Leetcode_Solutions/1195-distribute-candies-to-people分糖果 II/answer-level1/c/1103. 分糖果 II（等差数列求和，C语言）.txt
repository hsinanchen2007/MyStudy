【思路】糖果分发符合等差数列，计算时分为两步：1.找出可以完整拿到糖果数的轮回数，根据轮回数计算每个人在完整轮回可以获得的糖果数。2.最后一次分发不完整，按照手中糖果一次分发
![image.png](https://pic.leetcode-cn.com/c880f84ac92b739db0490d413272ea7492241f6efeb27d5eeb0f2472fb139dae-image.png)

```C
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *ans=(int*)malloc(sizeof(int)*(num_people+1));
    int i,tmp=1,circle=0;
    memset(ans,0,sizeof(ans));
    while(candies){
        if(candies>(1+tmp*num_people)*(tmp*num_people)/2)
        {circle++;tmp++;}
        else
            break;
    }
    candies-=(1+circle*num_people)*(circle*num_people)/2;
    tmp=circle*num_people+1;
    for(i=0;i<num_people;i++){
        ans[i]=circle*(i+1)+num_people*circle*(circle-1)/2;
        if(candies>=tmp){
            ans[i]+=tmp;candies-=tmp;
            tmp++;
        }else{
            ans[i]+=candies;candies=0;
            tmp++;
        }
    }
    *returnSize=num_people;
    return ans;
}
```
