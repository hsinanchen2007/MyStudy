### 解题思路
定义一个计数器，给while循环条件 num != 0，如果等于零了就退出循环，此时n的值就是步数

### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
        int n = 0;
        while(num != 0){
            if(num % 2 == 0){
                num = num / 2;
                n++;
            }else{
                num--;
                n++;
            }
        }
        return n;
    }

}
```