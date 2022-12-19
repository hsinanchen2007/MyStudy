第一种方式，也就是模拟卖柠檬水的方式，利用一个map来存储当前阶段所拥有的5美元和10美元的个数，一旦个数小于零就返回false.
```
 boolean lemonadeChange(int[] bills) {
        Map<Integer, Integer> map = new ConcurrentHashMap<>();
        map.put(5, 0);
        map.put(10, 0);        
        for (int i = 0; i < bills.length; i++) {
            if (bills[i] == 5) {
                map.put(5, map.getOrDefault(5, 0) + 1);
            }
            if (bills[i] == 10) {
                map.put(10, map.getOrDefault(10, 0) + 1);
                map.put(5, map.getOrDefault(5, 0) - 1);
                if (map.get(5) < 0) {
                    return false;
                }
            }
            if (bills[i] == 20) {
                if (map.get(10) >= 1 && map.get(5) >= 1) {
                    map.put(10, map.getOrDefault(10, 0) - 1);
                    map.put(5, map.getOrDefault(5, 0) - 1);
                    if (map.get(10) < 0 || map.get(5) < 0) {
                        return false;
                    }
                } else if (map.get(5) >= 3) {
                    map.put(5, map.getOrDefault(5, 0) - 3);
                    if (map.get(5) < 0) {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return true;
    }
```
第二种方式当然就是不用map存储，而直接用两个简单的字面量表示5美元和10美元的个数，同理小于零返回false。
```
boolean lemonadeChange2(int[] bills) {
        int five = 0;
        int ten = 0;
        for (int i = 0; i < bills.length; i++) {
            if (bills[i] == 5) {
                five++;
            } else if (bills[i] == 10) {
                five--;
                ten++;
                if (five < 0) {
                    return false;
                }
            } else {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                    if (ten < 0 || five < 0) {
                        return false;
                    }
                } else if (five >= 3) {
                    five -= 3;
                    if (five < 0) {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return true;
    }
```
第一种31ms，第二种2ms,同样的算法，不同的数据存储方式，耗时差很多，不过看了官方解答和自己的写法，感觉好好笑，发出来大家开心开心。

