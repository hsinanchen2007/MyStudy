### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck.length < 2){
            return false;
        }
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < deck.length; i++){
            if(!map.containsKey(deck[i])){
                map.put(deck[i], 1);
            }else{
                int v = map.get(deck[i]);
                map.put(deck[i], v+1);
            }
        }
        List<Integer> valuesList = new ArrayList<Integer>(map.values());
        int ans = valuesList.get(0);
        for(Integer i : valuesList){
            ans = gcd(ans, i);
        }

        return ans >= 2 ? true : false;
    }
    //最大公约数
    int gcd(int a, int b){
        if(a > b){
            if(b == 0){
                return a;
            }
            return gcd(b, a%b);
        }else{
            if(a == 0){
                return b;
            }
            return gcd(b%a, a);
        }
    }
}
```