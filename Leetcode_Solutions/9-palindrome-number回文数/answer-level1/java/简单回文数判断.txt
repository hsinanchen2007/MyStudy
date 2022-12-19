### 解题思路
先判断基本的小于0和等于0，然后取每一位，然后从一个从左到右遍历，另一个从右到左遍历。如果都一致那么是回文。反之不是

### 代码

```java
import java.lang.Math;
class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0){
            return false;
        }
         if(x == 0){
            return true;
        }
        int[] arr = new int[(int) Math.log10(x)+1];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = x % 10;
            x = x / 10;
        }
        int i = 0,j = arr.length-1;
        while(i <= j){
            if(arr[i] != arr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}
```