### 解题思路
在官方题解1上添加注释

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
      int[] count=new int[80000];
      for(int a:A) count[a]++;      /*统计数组A中每个数出现的次数*/
      int taken=0;int ans=0;
      for(int c=0;c<80000;c++){
          if(count[c]>1){            /*判断重复的数*/
              taken+=count[c]-1;     /*计算重复的数的个数*/
              ans-=c*(count[c]-1);   
           } else if((taken>0)&&(count[c]==0)){                /*未出现的数*/
              taken--;
              ans+=c;  
          }
      }
      return ans;
    }
}
```