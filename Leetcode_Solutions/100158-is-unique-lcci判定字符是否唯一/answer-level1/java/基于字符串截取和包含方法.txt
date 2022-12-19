### 解题思路
1.小于两位的字符串长度，直接true
2.大于两位每次截取第一位和剩下字符串比较，是否包含关系

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {

        String bstr = astr;
        if(astr.length() <= 1){
            return true;
        }
       
        for(int i = 0;i < bstr.length() - 1;i++){
            String sa = astr.substring(0,1);
            astr = astr.substring(1,astr.length());
            if(astr.contains(sa)){
                return false;
            }
        }
        return true;
        }
}
```