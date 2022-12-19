### 解题思路
先把整数n转成字符串类型的，然后遍历这个字符串。注意积应该初始化为1而不是0。

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        String num = n + "";
        int sum = 0;
        int plus = 1;
        //int[] a = new int[num.length()];
        for(int i=0;i<num.length();i++){
            sum += Integer.parseInt(num.substring(i,i+1));
            plus *= Integer.parseInt(num.substring(i,i+1));
        }
        return (plus-sum);
    }
}
```