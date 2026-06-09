### 解题思路
题目简单；2个for循环，先定义计数器，第一个循环对我有的石头遍历，放在第二个循环宝石进行比较，如果相等，计数器加一；然后跳出循环进行下一次比较。

### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        int count=0;
        char[] j1=J.toCharArray();
        char[] s1=S.toCharArray();
        for(int i=0;i<s1.length;i++){
            for(int j=0;j<j1.length;j++){
                if(s1[i]==j1[j]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}
```