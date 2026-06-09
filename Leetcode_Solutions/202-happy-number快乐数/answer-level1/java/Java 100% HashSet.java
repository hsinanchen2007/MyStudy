### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {


    
    public boolean isHappy(int n) {
      HashSet<Integer> res = new HashSet<>();
      while(n != 1){
          int current = n;
          int sum = 0;
          while(current != 0){
              sum += (current % 10) * (current % 10);
              current /= 10;
          }
          if(res.contains(sum)){
              return false;
          }

          res.add(sum);
          n = sum;
      }

      return true;
    }
}


```