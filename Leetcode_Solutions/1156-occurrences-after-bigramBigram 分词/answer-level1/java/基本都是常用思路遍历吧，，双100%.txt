
![image.png](https://pic.leetcode-cn.com/97df91888f16f069764f40421a7cd72c39cdd0f8c40cc2c047e2ed3278ecaa21-image.png)

```
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
    ArrayList<String> list = new ArrayList<String>();
        String [] str = text.split(" ");
        for (int i = 0; i < str.length - 2; i++){
            if (str[i].equals(first)&&str[i+1].equals(second)){
                list.add(str[i+2]);
            }
        }
        return list.toArray(new String[0]);
        
    }
}
```
