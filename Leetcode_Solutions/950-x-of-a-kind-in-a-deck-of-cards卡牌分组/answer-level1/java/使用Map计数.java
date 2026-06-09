### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer,Integer> map = new HashMap<>();
        for (int num : deck){
            map.put(num, map.getOrDefault(num, 0)+1);
        }
        int length = deck.length;
        for (int i=2; i<=length; i++){
            if (length%i!=0){
                continue;
            }
            boolean flag = true;
            for (int num : map.values()){
                if (num % i != 0){
                    flag = false;
                    break;
                }
            }
            if (flag) return flag;
        }
        return false;
    }
}
```