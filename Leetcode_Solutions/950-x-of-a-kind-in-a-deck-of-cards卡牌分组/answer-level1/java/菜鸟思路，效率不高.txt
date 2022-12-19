### 解题思路
暴力思路：
1、先map计数
2、在遍历values、看最大公约数是否 >= 2

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if (deck.length < 2){
            return false;
        }
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : deck){
            if (!map.containsKey(num)){
                map.put(num,1);
            }else{
                map.put(num,map.get(num) + 1);
            }
        }
        for (int i = 0; i < map.size(); i++){
            Integer value1 = (Integer) map.values().toArray()[i];
            if (value1 < 2){
                return false;
            }
            for (int j = i+1; j < map.size(); j++){
                Integer value2 = (Integer) map.values().toArray()[j];
                if (value1 < value2 && gcd(value2,value1) < 2){
                    return false;
                }else if (value1 > value2 && gcd(value1,value2) < 2){
                    return false;
                }
            }
        }
        return true;

    }
    private int gcd(int a, int b){
        return b == 0? a : gcd(b, a % b);
    }
}
```