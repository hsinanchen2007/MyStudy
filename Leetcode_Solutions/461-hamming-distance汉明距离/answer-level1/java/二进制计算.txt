### 解题思路
通过位运算和进制转换完成

### 代码

```java
class Solution {
    public int hammingDistance(int x, int y) {
        int temp=x^y;
        int j=temp%2;
        temp=temp/2;
        int count=j==1?1:0;
        while (temp!=0){
            j=temp%2;
            temp=temp/2;
            if(j==1){
                count++;
            }
        }
        return count;
    }
}
```