### 解题思路
直接使用已有的字符串处理方法

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        if(s != null && s != ""){
            String[] arr = s.split(" ");
            if(arr.length > 0){
                return arr[arr.length - 1].length();
            }else{
                return 0;
            }
        }else{
            return 0;
        }
    }
}
```