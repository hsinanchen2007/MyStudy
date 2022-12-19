### 解题思路
用哈希表实现的，思路应该很清楚。

### 代码

```java
class Solution {
    
    private HashMap<Character, Integer> hashmap = new HashMap<>();

    public void initialize(){
        hashmap.put('q', 1);hashmap.put('w',1);hashmap.put('e',1);hashmap.put('r',1);hashmap.put('t',1);
        hashmap.put('y',1);hashmap.put('u',1);hashmap.put('i',1);hashmap.put('o',1);hashmap.put('p',1);
        
        hashmap.put('a',2);hashmap.put('s',2);hashmap.put('d',2);hashmap.put('f',2);hashmap.put('g',2);
        hashmap.put('h',2);hashmap.put('j',2);hashmap.put('k',2);hashmap.put('l',2);
        
        hashmap.put('z',3);hashmap.put('x',3);hashmap.put('c',3);hashmap.put('v',3);hashmap.put('b',3);
        hashmap.put('n',3);hashmap.put('m',3);
    }

    public int findRow(char c){
        c = Character.toLowerCase(c);
        return this.hashmap.get(c);
    }

    public String[] findWords(String[] words) {
        if(words.length == 0)   
            return words;
        initialize();
        List<String> list = new ArrayList<>();

        boolean flag = true;
        for(int i = 0; i < words.length; i++){
            int j;
            flag = true;
            int row = findRow(words[i].charAt(0)); // 第一个字母是大写
            for(j = 1; j < words[i].length(); j++){
                if(row != findRow(words[i].charAt(j))){
                    flag = false;
                }
            }
            if(flag){
                list.add(words[i]);
            }
        }

        String[] res = new String[list.size()];
        for(int i = 0; i < list.size(); i++){
            res[i] = list.get(i);
        }
        return res;
    }
}
```