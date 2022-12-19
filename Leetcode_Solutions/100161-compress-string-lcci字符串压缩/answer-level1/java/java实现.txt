### 解题思路
    1.先将第一个字符添加到字符串中，
    2.次数计数count,初始值为1
    3.从i=1开始遍历，相等count++;否则跳出循环
    4.将count次数添加到字符串中，count从1重新计数
    5.比较两个字符串大小然后输出


### 代码

```java
class Solution {
    public String compressString(String S) {
    StringBuilder res = new StringBuilder();
        for(int i=0;i<S.length();i++){
            int count = 1;
            char c = S.charAt(i);
            res.append(c);
            for(int j=i+1;j<S.length();j++){
                char c1 = S.charAt(j);
                if(c==c1){
                    count++;
                    i++;
                }else {
                    break;
                }
            }
            res.append(count);
        }
        return S.length() <= res.length() ? S : res.toString();
    }
}
```