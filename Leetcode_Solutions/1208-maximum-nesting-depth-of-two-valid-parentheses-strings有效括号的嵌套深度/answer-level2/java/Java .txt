### 解题思路
尝试把if换成switch，发现还是2ms，40MB。
代码本质上还是遍历字符串，然后对比是左、右括号，接着按照奇偶数分组，最后输出结果。

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] res=new int[seq.length()];
        int depth=0;
        for(int i = 0;i<seq.length();i++){
            switch(seq.charAt(i)){
                case '(':
                    res[i]=depth++%2;//先赋值后自增
                    break;
                case ')':
                    res[i]=--depth%2;//先自减后赋值
                    break;
            }
        }
        return res;
    }
}
```