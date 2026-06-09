### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] res=new int[T.length];
        for(int i=0;i<T.length;i++){
            //count是记录当前T[i]大的个数的
            int count=0,j;
            for(j=i+1;j<T.length;j++){
                if(T[j]>T[i]){
                    res[i]=++count;
                    break ;
                }
                count++;
            }
            //res[T.length-1]当然要等于0，若count到了大于等于T.length的位置时，表示没有比T[i]大的数，所以也是0
            if(i==T.length-1||count>=T.length-i)res[i]=0;
        }
        return res;
    }
}
```