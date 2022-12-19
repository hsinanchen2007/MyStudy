### 解题思路
使用java中的map

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        char res=' ';
        Map<Character,Integer> map=new HashMap<>();
        int len=s.length();
        for(int i=0;i<len;i++){
            char ch=s.charAt(i);
            if(map.containsKey(ch)){
                map.put(ch,map.get(ch)+1);
            }else{
                map.put(ch,1);
            }
        }

        for(int i=0;i<len;i++){
            char ch=s.charAt(i);
            if(map.get(ch)==1){
                res=ch;
                break;
            }
        }

        return res;
    }
}
```