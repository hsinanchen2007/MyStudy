### 解题思路
while循环判断

### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
        int count = 0;
        while(num > 0){
            if(num % 2 == 0){
                num /=2;
                count++; 
            }else{
                num--;
                count++;
            }
        }
        return count;
    }
}
```