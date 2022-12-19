### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String boldWords(String[] words, String S) {
        //新建int数组
        int[] position = new int[S.length()+1]; //S.length()+1 主要是考虑到最后一个字符是否包含在关键字内
        for(int c: position) {
            c=0;
        }
        for(int i=0; i<words.length; i++){
            mark(position, words[i], S);
        }

        StringBuilder str = new StringBuilder();
        //判断首个字符串是否包含在关键字符内
        if(position[0]==1) str.append("<b>");
        for(int j=0; j<S.length(); j++){
            str.append(S.charAt(j));
            //判断是否转出关键字符区
            if(position[j]==1 && position[j+1]==0) {               
                str.append("</b>");
            } else if(position[j]==0 && position[j+1]==1) { //判断是否转入关键字符区
                str.append("<b>");
            }
            
        }
        return str.toString();


    }

    public void mark(int[] position, String key, String sample){
        int len = key.length();
        //判断是否含有关键字符串，并标记字符串区域位置
        for(int k=0; k<=sample.length()-len; k++) if(sample.length()>= len) {
            if(sample.substring(k, k+len).equals(key)){
                for(int i= k; i<k+len; i++){
                    position[i]=1;
                }
            }
        }
    }
}
```