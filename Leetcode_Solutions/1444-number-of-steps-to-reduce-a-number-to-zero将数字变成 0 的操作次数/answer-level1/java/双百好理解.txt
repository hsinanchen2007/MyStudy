### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
        int cnt = 0;
        while(num != 0){
            if(num%2 == 0){
            num >>= 1;
            }else{
                num--;
            }
            cnt++;
        }
        return cnt;
    }
}
```