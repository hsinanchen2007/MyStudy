![image.png](https://pic.leetcode-cn.com/2e64d4886ff303e5345920666c8b4903c3b4bbf609efb0aa9d7fc232f0df8789-image.png)

```
    private class Trade {
        private String s;
        private String name;
        private int time;
        private int money;
        private String city;
        private boolean valid;

        public Trade(String s, String name, int time, int money, String city) {
            super();
            this.s = s;
            this.name = name;
            this.time = time;
            this.money = money;
            this.city = city;
            this.valid = this.money > 1000 ? false : true;
        }

        @Override
        public String toString() {
            return s;
        }

        private boolean invalid(Trade o) {
            return this.name.equals(o.name) && !this.city.equals(o.city)
                    && Math.abs(this.time - o.time) <= 60;
        }
    }

    public List<String> invalidTransactions(String[] transactions) {
        List<String> result = new ArrayList<String>();
        List<Trade> trades = new ArrayList<Trade>();
        //先加入数组中
        for (String s : transactions) {
            String[] split = s.split(",");
            Trade t = new Trade(s, split[0], Integer.parseInt(split[1]), Integer.parseInt(split[2]),
                    split[3]);
            trades.add(t);
        }
        //判断
        for (int i = 0; i < trades.size(); i++) {
            Trade iTrade = trades.get(i);
            if (!iTrade.valid) {
                continue;
            }
            for (int j = 0; j < trades.size(); j++) {
                if (i == j) {
                    continue;
                }
                Trade jTrade = trades.get(j);
                if (iTrade.invalid(jTrade)) {
                    // 外部类能访问内部类的私有属性
                    iTrade.valid = false;
                    jTrade.valid = false;
                }
            }
        }
        for (Trade t : trades) {
            if (!t.valid) {
                result.add(t.toString());
            }
        }
        return result;
    }
```
