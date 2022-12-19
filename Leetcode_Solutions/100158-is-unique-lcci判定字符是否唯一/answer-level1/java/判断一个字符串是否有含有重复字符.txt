### 解题思路
取字符串第i个字符 并用for遍历i+1之后的字符 进行比较，如果有不同则跳出循环

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        boolean flag = true;
        outer:
        for(int i=0;i<astr.length()-1;i++){
            for(int j=i+1;j<astr.length();j++){
                if(astr.charAt(i)==astr.charAt(j)){
                    flag = false;
                    break outer;
                }
            }            
        }
        return flag;
    }
}
```