### 解题思路
执行用时：3 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗:39 MB, 在所有 Java 提交中击败了100.00%的用户
思路很简单，主要是优化了数据类型
1、将字符串转化为char数组进行运算
2、运用StringBuilder
3、简化语句，三元运算符
### 代码

```java
class Solution {
    public String compressString(String S) {
         int len=S.length();
        char[]array=S.toCharArray();
        if(S==null||len<=2)return S;
        int num=1;
        StringBuilder builder=new StringBuilder().append(array[0]);
        for (int i = 1; i < len; i++) {
            if(array[i]==array[i-1]){
                num++;
            }else {
                builder.append(num).append(array[i]);
                num=1;
            }
        }
        return builder.append(num).length()<S.length()?builder.toString():S;
        }
}
```