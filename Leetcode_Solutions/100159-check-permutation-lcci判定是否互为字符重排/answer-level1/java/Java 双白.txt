### 解题思路
此处撰写解题思路
建立两个大小为26的int类型数组，然后每次读一个字母就放入对应的位置，最后比较数组是否一致。
### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        int[] intArray1 = new int[26];
        int[] intArray2 = new int[26];
        for(int i = 0; i < 26 ; i++) {
            intArray1[i] = 0;
            intArray2[i] = 0;
        }
        for(int i = 0; i < s1.length(); i++) {
            intArray1[(int)s1.charAt(i) - 'a']++;
        }
        for(int i = 0; i < s2.length(); i++) {
            intArray2[(int)s2.charAt(i) - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(intArray1[i] != intArray2[i]) {
                return false;
            }
        }
        return true;
    }
}
```