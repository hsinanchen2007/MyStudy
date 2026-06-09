### 解题思路
此处撰写解题思路
负数直接返回false
正数循环 找到个位数字、十位数字 等
然后每找到一个数字就让转换的值*10
让原始值除以10
原始值为0终止
### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        int copyVal = x;
        if(x < 0) return false;
        int revserVal = 0;
        while(x > 0){
            int temp = x %10;
            revserVal= revserVal*10 + temp;
            x = x/10;
        }
        if(revserVal == copyVal){
            return true;
        }
        return false;
    }
}
```