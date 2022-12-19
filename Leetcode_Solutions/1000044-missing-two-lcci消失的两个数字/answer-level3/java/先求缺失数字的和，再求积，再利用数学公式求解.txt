### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] missingTwo(int[] nums) {
       int count=nums.length+2;
       int number=0,x=0,sum1,y=0;
       double sum=1;
       for(int i=1;i<=count;i++){
         number+=i;
         sum*=i;
         if(y<nums.length){
             sum/=nums[y];
            number-=nums[y];
              y++;
         }
       }
       sum1=(int)sum;
       if(sum>sum1+0.4)
       sum1++;
       for(int i=1;i<=count;i++){
           if(i*(number-i)==sum1){
               x=i;
           break;
           }
       }
      return new int[]{x,number-x};
    }
}
```