### 解题思路
1. 分别为词汇表和字母表建立一张哈希表
2. 比较字母表中是否包含词汇表的所有key,若不包含，则直接返回
3. 若包含，则比较字母表中的value值是否全部大于等于词汇表中的value值，若不成立，则直接返回

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        char ch[]=chars.toCharArray();
        Map<Character,Integer> map=new HashMap<>();
        int result=0;
        for(char c:ch){
            if(map.containsKey(c)){
                int count=map.get(c);
                count++;
                map.put(c,count);
            }else{
                map.put(c,1);
            }
        }

        for(String str:words){ 
            Map<Character,Integer> maptwo=new HashMap<>();
            char w[]=str.toCharArray();
            for(char c:w){
                if(maptwo.containsKey(c)){
                    int count=maptwo.get(c);
                    count++;
                    maptwo.put(c,count);
                }else{
                    maptwo.put(c,1);
            }
        }
        int i;
        for(i=0;i<w.length;i++){
            if(map.containsKey(w[i])==false){
                break;
            }
            if(map.get(w[i])<maptwo.get(w[i])){
                break;
            }
        }
        if(i==w.length){
                result+=w.length;
            }
    }
    return result;
    }
}
```