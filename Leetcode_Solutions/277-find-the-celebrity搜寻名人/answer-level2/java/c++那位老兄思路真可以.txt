### 解题思路
参照注解

### 代码

```java
/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
    public int findCelebrity(int n) {
        //定义i为名人候选人
        int i= 0;
        //用名人候选人去遍历所有人，如果名人候选人认识其中一人，则被认识的人就成为名人候选人
        for(int j=1;j<n;j++){
            if(knows(i,j)){
                i=j;
            }
        }
        //最后用最终选中的名人候选人去遍历其他人，看他是否认识其他人，或者其他人是否认识自己，来决定是不是名人
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            if(knows(i,j)){
                return -1;
            }
            if(!knows(j,i)){
                return -1;
            }     
        }
        return i;
    }
}
```