### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int compress(char[] chars) {
        if(chars.length==1){
            return 1;
        }
        char pre = chars[0];
        int pre_num = 1;
        StringBuffer result = new StringBuffer();
        for(int i=1;i<chars.length;i++){
            if(pre==chars[i]){
                pre_num += 1;
            }else{
                result.append(pre);
                if(pre_num>1){
                    result.append(pre_num);
                }
                pre_num=1;
                pre = chars[i];
            }
            if(i==chars.length-1){
                result.append(pre);
                if(pre_num>1){
                    result.append(pre_num);
                }
            }                      
        }
        char[]  chars2 =  result.toString().toCharArray();
        for(int i=0;i<chars2.length;i++){
            chars[i] = chars2[i];
        }
        return chars2.length;
    }
}
```