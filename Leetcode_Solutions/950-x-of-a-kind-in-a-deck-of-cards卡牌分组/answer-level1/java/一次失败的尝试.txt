### 解题思路
看了别人的思路，发现我好像想歪了，我是先获取了分组最小值，然后用这个值范围内的质数去对分组进行整除，能整除就证明可以分组
但这样其实做了很多不必要的循环操作，其实直接去获取所有分组的最小公约数就可以了
头脑还是不够灵活，需要更多锻炼

### 代码

```java
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;


class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < deck.length; i++) {
            if (map.containsKey(deck[i])) {
                map.put(deck[i], map.get(deck[i]) + 1);
            } else {
                map.put(deck[i], 1);
            }
        }
        int x = getMinValue(map);
        if (x < 2) {
            return false;
        } else {
            boolean flag = true;
            for(int i = 2; i<=x;i++){
                int j = 2;
                while (i % j != 0) {
                    j++; 
                }
                if (j == i){
                    flag = judge(map,i);
                    if(flag){
                        break;
                    }
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
    
    private boolean judge(Map<Integer, Integer> map,int x) {
        boolean flag = true;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() % x != 0) {
                flag = false;
                break;
            }
        }
        return flag;
    }

    private int getMinValue(Map<Integer, Integer> map) {
        if (map == null)
            return 0;
        Collection<Integer> c = map.values();
        Object[] obj = c.toArray();
        Arrays.sort(obj);
        return (int) obj[0];
    }
}
```