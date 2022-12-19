### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        int k = x;
        if(x<0){
            return false;
        }
        int rs = 0;
        while(k!=0){
            rs = rs*10 + k%10;
            k /= 10;
        }
        return (rs==x)?true:false;
        //循环里面x改变了，比较不是原来那个参数x了，要备份x用备份的来循环操作
    }
}
```