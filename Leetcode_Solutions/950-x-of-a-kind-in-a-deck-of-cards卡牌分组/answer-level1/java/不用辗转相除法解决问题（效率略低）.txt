### 解题思路
#### 首先使用哈希存放每个数字出现的次数；
#### 遍历哈希，找到最小值min；
#### 从使用k遍历2到min，用判断哈希表中是否能全部整除k；
#### 若可以，返回True，否则继续遍历
#### 最后返回False
### 代码

```java
class Solution {
     //卡牌分组
    public boolean hasGroupsSizeX(int[] deck) {
        HashMap<Integer, Integer> map = new HashMap<>();
        if (deck == null ||deck.length<2){
            return false;
        }
        int len = deck.length;
        for (int i = 0; i < len; i++) {
            map.put(deck[i],map.containsKey(deck[i])?map.get(deck[i])+1:1);
        }
        int min = Integer.MAX_VALUE;
        Set<Map.Entry<Integer, Integer>> entrySet = map.entrySet();
        for (Map.Entry<Integer,Integer> m:entrySet){
            min = min<m.getValue()?min:m.getValue();
        }
        if (min<=1){
            return false;
        }
        int k = 2;
        while(k<=min){
            boolean n = true;
            for (Map.Entry<Integer,Integer> m:entrySet){
                if (m.getValue()%k != 0){
                    n = false;
                    break;
                }
            }
            if (!n){
                k++;
            }else{
                return true;
            }
        }
        return false;
    }
}
```