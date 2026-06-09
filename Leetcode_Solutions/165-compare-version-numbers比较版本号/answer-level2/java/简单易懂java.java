### 解题思路
分割字符串，从前到后比较，考虑特殊情况

### 代码

```java
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] v1=version1.split("\\.");
        String[] v2=version2.split("\\.");
        int minLen=Math.min(v1.length,v2.length);
        for(int i=0;i<minLen;i++){
            if(Integer.parseInt(v1[i])>Integer.parseInt(v2[i])){
                return 1;
            }else if(Integer.parseInt(v1[i])<Integer.parseInt(v2[i])){
                return -1;
            }else{
                continue;
            }
        }
        //解决1和1.0 ，1.0.1的特殊情况
        if(v1.length<v2.length){
            for(int i=minLen;i<v2.length;i++){
                if(Integer.parseInt(v2[i])>0){
                    return -1;
                }
            }
        }
        if(v1.length>v2.length){
            for(int i=minLen;i<v1.length;i++){
                if(Integer.parseInt(v1[i])>0){
                    return 1;
                }
            }
        }
        return 0;
    }
}
```