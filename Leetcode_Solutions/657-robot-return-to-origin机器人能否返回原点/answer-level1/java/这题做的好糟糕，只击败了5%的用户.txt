我是想说以i，k分别为横纵变量，向左+1，向右-1，向上+1，向下j-1 最后如果ij均为初始值0则回到原点

### 代码

```java
class Solution {
    public boolean judgeCircle(String moves) {
         String s;
         int i,j,k;
         j = k = 0;
         for(i=0;i<moves.length();i++){
              s = moves.substring(i,i+1);
              if(s.equals("R")) j++;
              if(s.equals("L")) j--;
              if(s.equals("U")) k++;
              if(s.equals("D")) k--;
         }
         if(j==0 && k==0){
             return true;
         }
         return false;
    }
}
```