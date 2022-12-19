### 解题思路
**如果只是判断是否为偶数,与(&)比取余(%)效率要好**

### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
        int result=0;
        while (num>0){
            int i = num & 1;
            if(i== 1) {
                num=num-1;
                result+=1;
            }
            num = num >> 1;
            result+=1;
        }
        return --result;
    }
}
```