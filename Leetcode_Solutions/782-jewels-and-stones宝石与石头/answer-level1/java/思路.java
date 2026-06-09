### 解题思路
此处撰写解题思路
我的思路:
    就是将两个字符串进行比较，我们可以用两成循环，外面循环J的字符，里面的循环S中的字符，我们用
两个变量将J和S中的字符取出来，然后用if判断是否相等，如果相等的话，那就用创建一个统计的变量统计，最后返回这个统计的变量！
### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        char c;
        char k;
        int len=0;
        for(int i=0;i<J.length();i++){
            for(int j=0;j<S.length();j++){
                c=J.charAt(i);
                k=S.charAt(j);
                if(c==k){
                    len++;
                }
            }
        }
        return len;
    }
}
```