### 解题思路

把深度分摊到两个字符串中就行，因为字符串肯定是合法的，所以我们可以把左右括号分开分解
![1.png](https://pic.leetcode-cn.com/9fb17c9c0f9d339979ba2dac051ce49e44cb131d29b15eab78a1d52afa22a8e9-1.png)

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        char s[] = seq.toCharArray();
        int point = 0;
        int answer[] = new int[s.length];
        boolean flag = true;
        for(int i = 0;i<s.length;i++)
        {
            if(s[i]=='(')
            {
                if(flag) {answer[i]=0;flag = false;}
                else {answer[i]=1;flag=true;}
            }
            else
            {
                if(point%2==0) {answer[i]=0;point++;}
                else {answer[i]=1;point++;}
            }
        }
        return answer;//0 0 0 1 1 1
    }
}
```