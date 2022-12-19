### 解题思路
前后补0,为了边界值比较好算

### 代码

```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int[] flowerbed1=new int[flowerbed.length+2];
        for(int i=1;i<flowerbed1.length-1;i++)
        {
            flowerbed1[i]=flowerbed[i-1];    //前后补0
        }
        int pre=-1;
        int temp=0;
        int count=0;
        int i=0;
       for(i=0;i<flowerbed1.length;i++)
       {
           if(flowerbed1[i]==1)
           {
               temp=i;
               count+=getValue(pre,temp);     // 看两个1中间的0有多少个
               pre=temp;
           }
       }
       count+=getValue(pre,i);         //别忘了如果最后的1不在flowerbed1.length-1处                                          时, 最后也要算一下
       return count>=n?true:false;
    }


    private int getValue(int i,int j)
    {
        int temp=j-i-1;
        if(temp==0)
          return 0;
        if(temp%2==0)
        {
            return (temp-4)/2+1;
        }
        else
          return (temp-3)/2+1;
    }
}
```