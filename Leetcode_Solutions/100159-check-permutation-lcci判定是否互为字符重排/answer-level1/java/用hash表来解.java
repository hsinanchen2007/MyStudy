### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        
        if(s1.length() != s2.length()) return false; 
        int[] result = new int[255];
        for(int i = 0;i<s1.length();i++){
            result[s1.charAt(i)]++;
            result[s2.charAt(i)]--;
        }

        for(int i =0;i<255;i++){
            if(result[i] != 0){
                return false;
            }
        }
        return true;

    }
}
```