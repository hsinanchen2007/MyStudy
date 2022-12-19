### 解题思路
喵喵喵

### 代码

```java
class Solution {
    public int firstUniqChar(String s) {
        int index=-1;
        HashMap<Character,Integer>work=new HashMap<>();
        for(int i=0;i<s.length();i++){
            if(work.containsKey(s.charAt(i)))
                work.put(s.charAt(i),work.get(s.charAt(i))+1);
            else
                work.put(s.charAt(i),1);
        }
        for(int i=0;i<s.length();i++){
            if(work.get(s.charAt(i))==1){
                index=i;
                break;
            }
        }
        return index;
    }
}
```