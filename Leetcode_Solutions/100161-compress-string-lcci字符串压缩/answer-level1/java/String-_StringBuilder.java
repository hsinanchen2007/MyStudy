### 解题思路
解法一：直接用String，双重循环找相同的字符计数。但是每次更新String时都会重新建立一个String，耗费大量时间，而且双重循环本身耗时就很长
解法二：使用StirngBuider。需要注意的是使用String时并不需要判断字符串为空的情况，但是在使用StringBuider的时候就要提前判断。直接一次循环找当前字符与前面一个字符相同的个数。退出循环后要将最后一次找到的字符个数加在末尾。

解法一的代码比较简单粗暴，这里就不贴出来了，贴出解法二的代码供参考。

### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S==null || S.length()<=0){
            return S;
        }
        StringBuilder res=new StringBuilder();
        res.append(S.charAt(0));
        int sum=1;
        for(int i=1;i<S.length();i++){
            if(S.charAt(i)==S.charAt(i-1)){
                sum++;
            }else {
                res.append(sum).append(S.charAt(i));
                sum=1;
            }
        }
        res.append(sum);
        if(res.length()>=S.length()){
            return S;
        }
        return res.toString();
    }
}
```