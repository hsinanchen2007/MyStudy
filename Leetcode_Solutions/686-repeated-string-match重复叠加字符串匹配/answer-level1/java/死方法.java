### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int repeatedStringMatch(String A, String B) {
        int sum=A.length();
        for(int i=0;i<10000;i++){
            A=A+A.charAt(i);
        }
        int number;
        int num=A.indexOf(B);
        if(num==-1)
        return -1;
        number=num+B.length();
        if(number%sum==0)
        return number/sum;
        else
        return number/sum+1;
    }
}
```