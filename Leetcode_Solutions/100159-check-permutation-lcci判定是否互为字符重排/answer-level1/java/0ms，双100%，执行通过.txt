### 解题思路


### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if (s1.equals("") && s2.equals("")){
            return true;
        }
        if (s1.length()>100 || s2.length()>100){
            return false;
        }
        if (s1.equals("") && s2.length()<=100){
            return false;
        }
        if (s1.length()<=100 && s2.equals("")){
            return false;
        }
        if (s1.length()!=s2.length()){
            return false;
        }
        byte[] bytes1 = s1.getBytes();
        byte[] bytes2 = s2.getBytes();
        int total=0;
        int total1=0;
        for (int i=0;i<s1.length();i++){
            total+=bytes1[i];
            total1+=bytes2[i];
        }
        return total==total1;
    }
}
```