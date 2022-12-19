### 解题思路
分组递归

### 代码

```java
class Solution {
    public int countDigitOne(int n) {
        return dfs(n);
    }
    private int dfs(int n) {
        if(n<=0){
            return 0;
        }
        String numStr = String.valueOf(n);
        int high = numStr.charAt(0)-'0'; //最高位
        int below = (int) Math.pow(10,numStr.length()-1);
        int last = n - below*high;
        if(high==1){
            //例如 1234 high =1 below =1000 last = 234
            //分为3个部分 1000以下 、1~234里面、还有1000~1234 含1的合数
            // dfs(below) 0~999以下 中1的个数
            // dfs(last) 1~234 中1的个数
            // last+1 1000~1234中1的个数
            return dfs(below-1)+dfs(last)+last+1;
        }else{
            // 例如3456 high =3 below = 1000 last = 456
            // 里面包括3个部分
            // below 也就是 1000~1999上最高位1的个数
            // high*dfs(below-1) 也就是0~999、1000~1999(不算最高位)、2000~2999 1的个数
            // dfs(last) 也就是 0~456的1的个数
            return  below + high*dfs(below-1)+dfs(last);
        }
    }
}
```