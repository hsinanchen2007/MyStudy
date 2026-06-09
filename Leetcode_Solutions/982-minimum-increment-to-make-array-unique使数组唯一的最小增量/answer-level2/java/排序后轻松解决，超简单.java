### 解题思路
1、先排序
2、要解决的是元素重复的问题
3、在哪加1最后效果都相同

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        int result=0;
        Arrays.sort(A);
        if(A.length==0){
            return result;
        }
        int pre=A[0];
        for(int i=0;i<A.length;i++){
            if(i>0){
                while(A[i]<=pre){
                    A[i]+=1;
                    result+=1;
                }
                pre=A[i];
            }
            
        }
        return result;

    }
}
```