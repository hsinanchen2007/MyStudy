### 解题思路
一次通过，信心倍增，哈哈哈，无从下手的时候可以先写一写，调整调整，答案就出来了。

### 代码

```java
class Solution {
    Map<String, List<Transaction>> names = new HashMap<>();

    public List<String> invalidTransactions(String[] transactions) {
        HashSet<String> results = new HashSet<>();
        for (String string : transactions) {
            String[] strings = string.split(",");
            Transaction transaction = new Transaction(strings[0], Integer.parseInt(strings[1]), Integer.parseInt(strings[2]), strings[3]);
            if (transaction.amount > 1000) {
                results.add(string);
            }
            names.computeIfAbsent(transaction.name, k -> new ArrayList<>()).add(transaction);
        }
        if (transactions.length <= 1) {
            return new ArrayList<>(results);
        }
        for (Map.Entry entry : names.entrySet()) {
            List<Transaction> lists = (List<Transaction>) entry.getValue();
            for (int i = 0; i < lists.size() - 1; i++) {
                Transaction tmp1 = lists.get(i);
                for (int j = i + 1; j < lists.size(); j++) {
                    Transaction tmp2 = lists.get(j);
                    if (tmp1.city.equalsIgnoreCase(tmp2.city)) {
                        continue;
                    }
                    //同名不同城市60分钟内的交易
                    if (Math.abs(tmp1.time - tmp2.time) <= 60) {
                        results.add(changeToString(tmp1));
                        results.add(changeToString(tmp2));
                    }
                }
            }
        }
        return new ArrayList<>(results);
    }

    private String changeToString(Transaction tmp1) {
        StringBuffer stringBuffer = new StringBuffer();
        stringBuffer.append(tmp1.name).append(",");
        stringBuffer.append(tmp1.time).append(",");
        stringBuffer.append(tmp1.amount).append(",");
        stringBuffer.append(tmp1.city);
        return stringBuffer.toString();
    }

    class Transaction {
        String name;
        int time;
        int amount;
        String city;

        public Transaction(String name, int time, int amount, String city) {
            this.name = name;
            this.time = time;
            this.amount = amount;
            this.city = city;
        }
    }
}
```