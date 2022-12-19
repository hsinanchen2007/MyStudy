

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        if(n <= 0) return new int[0];
        int num = 1;
        while(n != 0){
            num *= 10;
            n--;
        }
        int[] res = new int[num-1];
        int count = 0;
        while(count != res.length){
            res[count] = count + 1;
            count ++;
        }
        return res;
    }
}
```