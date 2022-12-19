### 解题思路

使用头尾指针，左指针：l  , 右指针 ： r ;
交换头尾指针的位置的值即可

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        int l=0,r=s.length-1;
        for(int i=0;i<s.length/2;i++){
            char temp=s[l];
            s[l++]=s[r];
            s[r--]=temp;
           
        }


    }
}
```