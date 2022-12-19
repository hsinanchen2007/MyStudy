### 解题思路
设nums[i]前的最大连续子串积max，最小min；则当前nums[i]的max为max*nums[i]、nums[i]、min*nums[i]中的最大值，min为三者的最小值

### 代码

```c

#define Max(a,b)  a>b?a:b
#define Min(a,b)  a<b?a:b

int maxProduct(int* nums, int numsSize){

    int max=nums[0],min=nums[0],result=nums[0],i=0,temp;
    

    for(i=1;i<numsSize;i++)
    {   temp=max;
        max=Max((max*nums[i]),(min*nums[i]));
        max=Max(max,nums[i]);
        min=Min((temp*nums[i]),(min*nums[i]));
        min=Min(min,nums[i]);

        result=Max(max,result);

    }
    return result;

}
```