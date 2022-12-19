### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck.length == 0){
            return false;
        }
        Map<Integer, Integer> map = new HashMap<>();
        for(int i: deck){
            map.put(i, map.getOrDefault(i, 0)+1);
        }
        int count = 0;
        int tmp = 1;
        for(Map.Entry<Integer, Integer> entry: map.entrySet()){
            if(count == 0){
                tmp = entry.getValue();
                count++;
                continue;
            }
            tmp = getBigDiv(tmp, entry.getValue());
        }
        return tmp != 1;
    }

    public int getBigDiv(int a, int b){
        while(a%b != 0){
            int tmp = a%b;
            a = b;
            b = tmp;
        }
        return b;
    }
}
```