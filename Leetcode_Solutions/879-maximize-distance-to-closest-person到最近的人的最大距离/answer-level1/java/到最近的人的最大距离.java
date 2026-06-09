### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxDistToClosest(int[] seats) {
        if(seats.length==2)
        return 1;
        int number=0,count=0,sum=0,max=0;
        for(int i=0;i<seats.length;i++){
            number=0;count=0;
            if(seats[i]==0){
                for(int k=i-1;k>=0;k--){
                    if(seats[k]==1){
                       number=i-k;
                       break;
                    }
                }
                for(int k=i+1;k<seats.length;k++){
                    if(seats[k]==1){
                        count=k-i;
                        break;
                    }
                }
                if(number==0)
                sum=count;
                else if(count==0)
                sum=number;
                else if(number<count&&number!=0&&count!=0)
                sum=number;
                else sum=count;
            }
            if(sum>max)
            max=sum;
        }
        return max;
    }
}
```