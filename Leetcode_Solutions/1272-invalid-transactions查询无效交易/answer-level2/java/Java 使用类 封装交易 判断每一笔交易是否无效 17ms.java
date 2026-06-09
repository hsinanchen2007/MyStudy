![1169.png](https://pic.leetcode-cn.com/06067956a9098e3901ae0b278174adb1a3804bdf764dd3b7498a2fa04dcabb69-1169.png)

---

```java
class Solution {
    public List<String> invalidTransactions(String[] transactions) {
        Transaction[] trans = new Transaction[transactions.length];
        int index = 0;
        for(String tran : transactions){
            String[] strings = tran.split(",");
            trans[index++] = new Transaction(strings[0],Integer.parseInt(strings[1]),Integer.parseInt(strings[2]),strings[3]);
        }
        List<String> list = new ArrayList<>();
        for(int i=0;i<trans.length;i++){
            if(trans[i].money>1000)list.add(transactions[i]);
            else{
                for(int j=0;j<trans.length;j++){
                    if(i!=j && trans[j].name.equals(trans[i].name) && !trans[j].city.equals(trans[i].city)
                            && Math.abs(trans[j].time - trans[i].time)<=60){
                        list.add(transactions[i]);
                        break;
                    }
                }
            }
        }

        return list;
    }
}
class Transaction{
    String name;
    Integer time;
    Integer money;
    String city;

    public Transaction(String name, Integer time, Integer money, String city) {
        this.name = name;
        this.time = time;
        this.money = money;
        this.city = city;
    }
}

```
