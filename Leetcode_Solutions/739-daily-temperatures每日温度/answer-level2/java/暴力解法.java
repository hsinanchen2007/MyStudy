### 解题思路
此处撰写解题思路
使用数组res存储结果。
对于T中的每一个元素T[i],从j=i+1处开始比较T[i]和T[j]的大小，当T[j]>T[i]时，res[i]=j-i,退出内循环。
### 代码

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
      int[] res=new int[T.length];
      for(int i=0;i<T.length;i++){
          int j=T.length;;
          if(i+1<T.length){
              j=i+1;
          }
          while(j<T.length){
              if(T[j]>T[i]){
                  res[i]=j-i;
                  break;
              }
              j++;
          }
      }
      return res;
    }
}
```