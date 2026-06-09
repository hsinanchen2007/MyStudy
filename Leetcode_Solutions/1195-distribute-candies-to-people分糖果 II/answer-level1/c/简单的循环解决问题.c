### 解题思路
![image.png](https://pic.leetcode-cn.com/b0ef1dd95c43f660e9b8e08669e2318007ef577d04afec684885d2ef3aaeafc2-image.png)
* 对特殊情况做一个分享（candies==0||num_people==0）
* 定义一个num_people长度的动态数组，然后赋初值
* 然后进入循环（candies>0），如果candies大于等于将要分配的糖果数，就按规律分配，否则就把剩余全部糖果直接分配
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
       if(candies==0||num_people==0)
       {
           *returnSize=0;
           return NULL;
       }
       * returnSize=num_people;
       int *ans=(int *)malloc(sizeof(int)*num_people);
       int i;
       for(i=0;i<num_people;i++)
          ans[i]=0;
       //int pre_num=0; //前一个分配的数量
       int cur_num=1; //当前要分配的数量
       i=0;
       while(candies>0)
       {
         if(candies>=cur_num)
           {
               ans[i]=ans[i]+cur_num;
               candies=candies-cur_num;
               i=(i+1)%num_people;
               cur_num++;
           }
          else
          {
              ans[i]=ans[i]+candies;
              candies=candies-cur_num;
          }

       }
       return ans;

}
```