### 解题思路
执行用时 :
0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :35.9 MB, 在所有 Java 提交中击败了100.00%
的用户


### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
    
      if(1==num) {
          return 1;
      }
     if(0==num%2){
          return 1+numberOfSteps(num>>1);
     } else{
       return 1+numberOfSteps(num-1);
     }
      
    }
}
```