这道题难度不大，主要是for循环的终止条件，要注意数组越界
```
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String[] words = text.split(" ");
        List<String> res = new LinkedList<>();
        for(int i = 0;i < words.length - 2;i++){
            if(words[i].equals(first) && words[i + 1].equals(second)){
                res.add(words[i + 2]);
            }
        }
        
        return res.toArray(new String[res.size()]);
    }
}
```
