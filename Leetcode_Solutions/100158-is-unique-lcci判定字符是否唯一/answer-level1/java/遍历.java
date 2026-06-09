### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
     int[] c=new int[128];
     for(int i=0;i<astr.length();i++){
         c[astr.charAt(i)]++;
     }
     for(int j=0;j<128;j++){
         if(c[j]>1)return false;
     }
     return true;
    }
}
```