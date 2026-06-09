![image.png](https://pic.leetcode-cn.com/b0f9c155cb468f830e31779bc3489f0118198f3421f04fbc584b3f1f9c902b40-image.png)


### 解题思路

大体思路和官方动态规划方法类似，对第二层循环进行优化
f[i] 表示s.substring(0,i)是否可以用wordDict表示
第一层i遍历字符串长度
原先第二层j遍历0 ~ i,判断 wordDict中是否存在 s.substring(j, i)
优化后第二层遍历 wordDict 的每一个word,判断word是否位于s.substring(0, i)末尾

### 代码

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int m = s.length();
        if (s.length() == 0) return false;
        boolean[] f = new boolean[m + 1];
        f[0] = true;

        for(int i = 1; i <= s.length(); i++){
            for(String w: wordDict){
                int len = w.length();
                if(i >= len && f[i - len] == true 
                && s.substring(i - len, i).equals(w)){
                    f[i] = true;
                    break;
                }
            }

            // for(int j = 0; j < i; j++){
            //     if(f[j] == true && wordDict.contains(s.substring(j, i))){
            //         f[i] = true;
            //         break;
            //     }
            // }
        }
        return f[m];
    }
}
```