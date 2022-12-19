### 解题思路
各种情况需要考虑周全，否则逻辑容易出错

### 代码

```java
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] s1 = version1.split("\\.");
        String[] s2 = version2.split("\\.");
        int length = Math.max(s1.length,s2.length);
        int temp1 = -1;
        int temp2 = -1;
        for(int i=0;i<length;i++){
            //如果哪个字符串已经没有长度，就把它设置成0.
            if(i>=s1.length || i >= s2.length){
                if(i>=s1.length){
                    temp1 = 0;
                    temp2 = Integer.parseInt(s2[i]);

                }else{
                    temp1 = Integer.parseInt(s1[i]);
                    temp2 = 0;
                }
            }
            else{
                temp1 = Integer.parseInt(s1[i]);
                temp2 = Integer.parseInt(s2[i]);
            }
            if(temp1>temp2){
                return 1;
            }else if(temp1<temp2){
                return -1;
            }
        }
        return 0;

    }
}
```