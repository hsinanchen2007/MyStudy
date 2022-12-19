### 解题思路
转化为字符数组，遍历进行暴力求解。

### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        char[] Js = J.toCharArray();
        char[] Ss = S.toCharArray();
        int count = 0;
        for(int i = 0;i<J.length();i++){
            for(int j = 0;j<S.length();j++){
                if(Js[i]==Ss[j]){
                    count++;
                }else{
                    continue;
                }
            }
        }
        return count;
    }
}
```