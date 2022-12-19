### 解题思路
char[]反向添加元素，完美

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        int length =0;
        for(char ch:s.toCharArray()){
            if(ch == ' '){
                length += 3;
            }else{
                length+=1;
            }
        }
        char[] arr = new char[length--];
        for(int i =s.length()-1; i>=0 ; i--){
            if(s.charAt(i) == ' '){
                arr[length--] = '0';
                arr[length--] = '2';
                arr[length--] = '%';
            }else{
                arr[length--] = s.charAt(i);
            }    
        }
        return  new String(arr);
    }
}
```