### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        //对数组进行排序
        Arrays.sort(A);
        int i=0;
        int count=0;
        for(i=1;i<A.length;i++){
            //如果这个当先等于前一个，当重复超过2个就会出现小于
            if(A[i]<=A[i-1]){
                //使当前数增加到比前一个数大1；
                int pre=A[i];
                A[i]=A[i-1]+1;
                //统计总共增加了多少
                count += A[i]-pre;
            }
        }
        return count;
    }
}
```