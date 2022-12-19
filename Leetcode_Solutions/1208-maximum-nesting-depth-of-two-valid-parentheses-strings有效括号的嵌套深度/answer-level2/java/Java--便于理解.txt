### 解题思路
* 将奇数的所有左括号，分给A，右括号分给B；偶数的所有右括号分给A，左括号分给B
* 可以保证A和B都不会出现连续的左括号或者右括号

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int [] res = new int[seq.length()];
        for (int i = 0; i < seq.length(); i++) {
            if (i%2==0){
                if (seq.charAt(i)=='('){
                    res[i]=0;
                }else {
                    res[i]=1;
                }
            }else {
                if (seq.charAt(i)=='('){
                    res[i]=1;
                }else {
                    res[i]=0;
                }
            }
        }
        return res;
    }
}
```