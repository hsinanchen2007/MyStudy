### 解题思路
利用字符的ASCII破题，大家看看有没问题
### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        char[] str = astr.toCharArray();
        int[] arr = new int[128];
        for(int i=0;i<arr.length;i++){
            arr[i] = -1;
        }
        for(int i=0;i<str.length;i++){
            int index = (int)str[i];
            if(arr[index] != -1){
                return false;
            }else{
                arr[index] = 0;
            }
        }
        return true;
    }
}
```