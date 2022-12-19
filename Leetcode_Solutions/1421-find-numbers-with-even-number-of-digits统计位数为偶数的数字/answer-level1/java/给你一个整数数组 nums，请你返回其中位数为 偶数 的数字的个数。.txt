### 解题思路
int numberOfDigits = String.valueOf(num).length();

static String valueOf(int i):返回int参数的字符串 int形式。  

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int i = 0;
        for(int num : nums){
            if((String.valueOf(num).length() % 2) == 0){
                i++;
            }
        }
         return i;
    }
}


```