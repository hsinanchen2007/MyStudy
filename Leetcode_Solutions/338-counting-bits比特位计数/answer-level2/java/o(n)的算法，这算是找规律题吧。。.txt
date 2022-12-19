### 解题思路
我这个算法就是O(n)的算法
### 代码

```java
class Solution {
    public int[] countBits(int num) {
        if(num==0)
            return new int[1];
        int[] res=new int[num+1];
        int sum=0,gap=1,index=1,i=2;
        res[0]=0;res[1]=1;
        do{
            gap=1<<index;
            for(int k=gap;k!=0;k--,i++){
                if(i>num)
                    break;
                res[i]=res[i-gap]+1;
            }
            index++;
        }while(i<=num);
        return res;
    }
}
```