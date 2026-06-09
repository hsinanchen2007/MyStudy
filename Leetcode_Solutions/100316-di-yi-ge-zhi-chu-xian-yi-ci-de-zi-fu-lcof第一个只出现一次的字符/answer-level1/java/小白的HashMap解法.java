### 解题思路
都是看了知乎god-jiang的文章，才变得厉害起来

### 复杂度分析
- 时间复杂度：O(N)
- 空间复杂度：O(N)

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        if(s==null||s.length()==0){
            return ' ';
        }
        HashMap<Character,Integer> map=new HashMap<>();
        for(int i=0;i<s.length();i++){
            if(map.containsKey(s.charAt(i))){
                map.put(s.charAt(i),2);
            }else{
                map.put(s.charAt(i),1);
            }
        }
        for(int i=0;i<s.length();i++){
            if(map.get(s.charAt(i))==1){
                return s.charAt(i);
            }
        }
        return ' ';
    }
}
```