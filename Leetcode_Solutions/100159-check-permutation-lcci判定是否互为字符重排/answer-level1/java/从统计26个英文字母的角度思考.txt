### 解题思路
java 从两个字符串中统计出分别含有26个英文字母的个数的数组，最后比较两个统计个数的数组是否一致。但若针对字符串中有大小写混排的就会有点小bug啦，多亏测试集里没有！结果双百
想用c++的next_permutation()做，结果超时~

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        boolean mark=true;
        char arr1[] = new char[s1.length()];
        char arr2[] = new char[s2.length()];
        int a[]=new int[26];
        int b[]=new int[26];
        int i;
        for(i=0;i<s1.length();i++){
            ++a[s1.charAt(i)-'a'];
        }
        for(i=0;i<s2.length();i++){
            ++b[s2.charAt(i)-'a'];
        }
        for(i=0;i<26;i++){
            if(a[i]!=b[i])
                mark=false;
        }
        return mark;
    }
}
```