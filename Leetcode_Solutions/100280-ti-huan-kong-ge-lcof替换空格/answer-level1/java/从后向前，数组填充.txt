### 解题思路
用数组实现，时间复杂度O(n),额外空间O(n)。
首先计算新数组的长度（s.length()+count*2），
然后初始化字符数组，从后向前添加元素。
最后再用String包装数组。

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        int count = 0;
        int len = s.length();
        for(int i = 0 ; i < len ; i++){
            if(s.charAt(i) == ' '){
                count++;
            }
        }
        char[] ch = new char[s.length()+count*2];
        int i = len-1,j = ch.length-1;
        while(i > -1 && j > -1){
            if(s.charAt(i) == ' '){
                ch[j] = '0';
                ch[j-1] = '2';
                ch[j-2] = '%';
                i--;
                j -= 3;
            }else{
                ch[j] = s.charAt(i);
                i--;
                j--;
            }
        }
        return new String(ch);
    }
}
```