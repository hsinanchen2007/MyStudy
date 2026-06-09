### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int i = 0;
        boolean flag = false;
        for(; i < bits.length;){
            if(bits[i] == 1){
                i += 2;
                flag = false;
            }else if(bits[i] == 0){
                i += 1;
                flag = true;
            }
        }
        return flag;
    }
}
```