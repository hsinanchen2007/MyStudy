### 解题思路
暴力求解 和上周的一道题好像 但仔细看 还是有点区别的

### 代码

```java
class Solution {
    public String compressString(String S) {
        HashMap<String,Integer> mMaps = new HashMap<>();
        char[] collects = S.toCharArray();
        StringBuffer sb = new StringBuffer();
        int j = 1;
        for(int i = 0 ; i < collects.length; i++){
            if(i == 0){
                sb.append(collects[i]);
            }
            if(i != 0){
                if(String.valueOf(collects[i]).equals(String.valueOf(collects[i-1]))){
                j++;
            }else{
                sb.append(j);
                sb.append(collects[i]);
                j = 1;
            
            }
            }
        }
        sb.append(j);
        if(sb.toString().length() >= S.length()){
            return S;
        }else{
            return sb.toString();
        }
    }
}
```