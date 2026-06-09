### 解题思路
遍历获取下标 如果存在宝石列中就+1

### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        int num = 0;
        for (char c : S.toCharArray()) {
            if(J.indexOf(c)>-1){
                num ++;
            }
        }
        return num;
    }
}
```