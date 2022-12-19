### 解题思路
有点慢啊，怎么优化呢？

### 代码

```java
class Solution {
    public int romanToInt(String s) {
         HashMap<String,Integer> maps = new HashMap<String, Integer>();
        maps.put("I",1); maps.put("V",5);
        maps.put("X",10); maps.put("L",50);
        maps.put("C",100); maps.put("D",500);
        maps.put("M",1000);
        char[] chars = s.toCharArray();
        int sum = 0;
        if(chars.length == 1){
            return maps.get(s);
        }
        for (int i = 0 ;i <chars.length - 1;i++){
             if(maps.get(String.valueOf(chars[i])) >= maps.get(String.valueOf(chars[i+1])) ){
                 sum += maps.get(String.valueOf(chars[i]));
             }else{
                 sum += -maps.get(String.valueOf(chars[i]));
             }
        }
        sum += maps.get(String.valueOf(chars[chars.length-1]));
        return sum;             
    }
}
```