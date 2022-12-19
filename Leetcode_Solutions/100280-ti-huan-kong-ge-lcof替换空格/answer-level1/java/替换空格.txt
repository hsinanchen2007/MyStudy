### 解题思路
根据字符串中空格的个数创建数组的长度：字符串长度 + 2 * 空格个数。
后续优化：可以放在一个数组中。

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        if(s == null || s.length() == 0){
            return s;
        }

        int count = 0; 
        int length = s.length();
        for(int i = 0; i < length; i++){
            if(s.charAt(i) == ' '){
                count += 1;
            }
        }

        char[] arr = new char[length + count * 2];
        int point = length + count * 2 - 1 ;
        
        for(int i = length - 1; i >= 0; i--){
            if(s.charAt(i) == ' '){
                arr[point] = '0';
                arr[point - 1] = '2';
                arr[point - 2] = '%';
                point = point - 3;
            }else{
                arr[point--] = s.charAt(i);
            }
        }

        return new String(arr);

    }
}
```