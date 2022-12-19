看到这道题通过率低，我一次就写出来了，就忍不住分享一下。我的这个写法，执行用时和内存消耗，都比较多，不太好，也就理解起来好理解一点。

### 解题思路
因为所分的组中，所有牌型是一样的，所以要先把所有牌型的数量整出来。

先遍历整副牌，把所有牌型都有多少个整出来，放到map集合里面。

然后遍历map集合，找到牌数量最少的牌型有多少个。

然后从2开始，增加到牌型数量最少的那个数min。看是否存在一个数量X，能让所有牌型的数量都整除。

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        //用来存储牌的大小和对应的数量
        Map<Integer, Integer> num = new HashMap<Integer, Integer>();
        for (int i : deck){
            //两种写法等价
            //if(num.get(i)==null){num.put(i,1);}else{num.put(i,num.get(i)+1);}
            num.put(i, num.get(i) == null ? 1 : num.get(i) + 1);
        }
        Set<Integer> keys = num.keySet();
        //找出所有牌数里面数量最少的，确定循环次数
        int min = 0;
        for (Integer i : keys){
            //两种写法等价
            //min = min == 0 ? num.get(i) : (min > num.get(i) ? num.get(i) : min);
            if (min == 0) min = num.get(i);
            if (min > i) min = num.get(i);
        }
        if (min < 2) return false;
        //标记遍历完一轮牌后，是否所有的牌数都能被X整除
        boolean flag = true;
        for (int x = 2; x <= min; x++){
            for (Integer n : keys){
                if (num.get(n) % x != 0){
                    flag = false;
                    break;
                }
            }
            //如果所有的牌数都整除了，返回true，而存在没有整除的牌数时，数量加一进行下次循环
            if (flag){
                return true;
            }else{
                flag = true;
            }
        }
        return false;
    }
}
```