### 解题思路
此处撰写解题思路
根据题意可以得到,每次移动只能递增1,返回最少的操作,数组的顺序不会影响最终结果
先排序,只要保证A[i]>=A[i-1]+1这样数组元素就不会相同,并且只增加1,移动次数也是最少的
### 代码

```java
class Solution {
    public  int minIncrementForUnique(int[] A) {
        if(A.length<=1){
            return 0;
        }
        Arrays.sort(A);
        int result=0;
        int pre=A[0];
        for(int i=1;i<A.length;i++){
            //如果A[i]>=A[i-1]+1不需要移动,因为本身就是不重复的
            if(A[i]>=pre+1){
               pre=A[i]; 
            }else{
               //开始move操作,只要move操作到 A[i]=A[i-1]+1,一定是最少次数,统计move的次数
              result=result+(pre+1-A[i]);
            //修改A[i-1]的值,进行下一轮比较
              pre=pre+1; 
            }
        }
        return result;
    }
}
```