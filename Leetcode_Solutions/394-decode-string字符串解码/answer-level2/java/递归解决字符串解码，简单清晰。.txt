### 解题思路
此处撰写解题思路
将[]中的字符串作为递归的单位，没有[]则直接添加。
### 代码

```java
class Solution {
    public String decodeString(String s) {
        return decodeItem(s,0,s.length());
    }

    //递归【】中的字符串
    private String decodeItem(String s,int i,int end){
        String ss  = s.substring(i,end);
        if(!ss.contains(String.valueOf('[')) && !ss.contains(String.valueOf(']'))){
            return ss;
        }
        StringBuilder sb = new StringBuilder();
        while(i < end){
            char c = s.charAt(i);
            if(c >= '0' && c <= '9'){
                //获取重复次数k最近的一个“【”的索引
                int index = s.indexOf("[",i);
                int match = findEnd(s,index+1);
                for(int j=0;j<Integer.valueOf(s.substring(i,index));j++){
                    //递归添加字符串
                    sb.append(decodeItem(s,index+1,match));
                }
                
                i = match;
            }else if((c != '[') && (c != ']')){
                sb.append(c);
            }
            i++;
        }
        return sb.toString();
    }
    //找到“【”配对的 “】”的索引
    private int findEnd(String s,int i){
        int sc = 0;
        while(i < s.length()){
            char c = s.charAt(i);
            if( c == '['){
                sc++;
            }else if(c == ']'){
                sc--;
                if(sc == -1){
                    return i;
                }
            }
            i++;
        }
        return i;
    }
}
```

时间复杂度为 O(n), 空间复杂度O(n)