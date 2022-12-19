### 解题思路
计算数组大小，注意越界

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int count = pow(10,n) - 1;
        if(count <=0){
            return null;
        }
        int[] result = new int[count];
        for(int i = 0; i < count; i++){
            result[i] = i + 1;
        }
        return result;
    }

    public int pow(int x, int y){
        int result = 1;
        for(int i = 0; i< y; i++){
            result *= x;
        }
        return result;
    }
}
```