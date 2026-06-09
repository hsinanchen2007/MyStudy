### 解题思路
先判断是否出现这几个单词，防止后面map.get()方法为空的情况，然后分别取ban和lo里的最小值，最后判断一次x和y的关系

### 代码

```java
class Solution {
    public int maxNumberOfBalloons(String text) {
        if(!text.contains("b") || !text.contains("a") || !text.contains("l") || !text.contains("o") || !text.contains("n")){
            return 0;
        }
        Map<Character,Integer> map = new HashMap<>();
        for(char c : text.toCharArray()){
            map.put(c,map.getOrDefault(c,0)+1);
        }
        int x = Math.min(Math.min(map.get('b'),map.get('a')),map.get('n'));
        int y = Math.min(map.get('l'),map.get('o'));
        if(y >= 2*x){
            return x;
        }else{
            return y/2;
        }
    }
}
```