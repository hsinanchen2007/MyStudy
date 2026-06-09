### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String str) {

        Map<Character,Integer> map = new HashMap<>();
        //toCharArray(),将string转化成字符数组
        char[] ch = str.toCharArray();
        for(char c:ch){
            if(map.containsKey(c)){
                return false;
            }
            map.put(c,1);
        }
        return true;
    }
}
```