### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        boolean result = true;
        char []a = String.valueOf(x).toCharArray();
        if(a.length == 1){
            if(x<0)
            result = false;
            else
            return result;
        }else if(a.length == 2){
            if(a[0] == a[1]){
                result = true;
            }else{
                result = false;
            }
        }else{
            for(int i=0;i<a.length;i++){
                if(i!=a.length/2){
                    if(a[i] == a[a.length-1-i]){
                        continue;
                    }  else{
                        result = false;
                    } 
                }
            }
        }
        return result;
    }
}
```