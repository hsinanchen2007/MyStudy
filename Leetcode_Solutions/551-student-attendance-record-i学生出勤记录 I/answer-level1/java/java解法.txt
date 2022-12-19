### 解题思路
直接看代码 ，肯定能看懂  A的个数大于1，直接返回false， L连着三个直接返回false。 其他的就进入下一次循环，最后返回true

### 代码

```java
class Solution {
    public boolean checkRecord(String s) {
        int countA = 0;
       for(int i = 0; i < s.length(); i++){
           if(s.charAt(i) == 'A'){
                countA++;
            }
            if(countA > 1)
                return false;
            if(s.charAt(i) == 'L' && (i + 2) < s.length() && s.charAt(i + 1)== 'L' && s.charAt(i + 2) == 'L')
                return false;
        }
        return true;
    }
}
```