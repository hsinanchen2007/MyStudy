### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int multiply(int A, int B) {

          int sum=A+B;
          A= Math.max(A,B);
          B= sum-A;
          
          if(B==0)
          {
              return 0;
          }
          if(B==2)
          {
              return A+A;
          }
          
          
          if(B%2==0)
          {
              int half=multiply(A,B/2);
              return half+half;
          }
          else {
              int half=multiply(A,B/2);
              return half+half+A;
          }
          


      }
}
```