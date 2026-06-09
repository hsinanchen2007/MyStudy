### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
	

    public static   int longestPalindrome(String s) {
        int target =0;
Map<String,Integer> map = new HashMap<String,Integer>();
for(int i=0;i<s.length();i++){
    if(!map.containsKey(String.valueOf(s.charAt(i)))){
        map.put(String.valueOf(s.charAt(i)),1);
    }else{
       int b = map.get(String.valueOf(s.charAt(i)))+1;
       map.put( String.valueOf(String.valueOf(s.charAt(i))),b);
    }
}

    for(Map.Entry<String,Integer> a:map.entrySet()) {
    if(a.getValue()%2==0){
        target = target+ a.getValue();
    }else{
        target = target+ a.getValue()-1;
    }
}
    for(Map.Entry<String,Integer> a:map.entrySet()) {
    if(a.getValue()%2==1){
        target = target+ 1;
        break;
    }
}

return target;
    }
}
```