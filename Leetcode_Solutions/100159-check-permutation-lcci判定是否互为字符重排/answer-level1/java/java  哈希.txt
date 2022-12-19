### 解题思路

使用数组代替hashmap,节省空间

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if(s1.length()!=s2.length()) return false;
        int[] num1 = new int[128];
        int[] num2 = new int[128];
        for(int i=0 ; i<s1.length() ; i++){
            num1[s1.charAt(i)] += 1;
            num2[s2.charAt(i)] += 1;
        }
        for(int i=0 ; i<128 ; i++){
            if(num1[i] != num2[i]){
                return false;
            }
        }
        return true;
    }
}
```