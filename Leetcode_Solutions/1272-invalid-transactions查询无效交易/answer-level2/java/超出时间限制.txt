```
class Solution {
    public List<String> invalidTransactions(String[] transactions) {
        List<String> li = new ArrayList<String>();
        int i,j;
        for(i = 0;i < transactions.length;i++){
            String s[] = transactions[i].split(",");
            int k = Integer.parseInt(s[2]);
            if(k > 1000 && !li.contains(transactions[i]))
                li.add(transactions[i]);
        }
        for(i = 0 ; i < transactions.length - 1;i++){
            String s1[] = transactions[i].split(",");
            int k1 = Integer.parseInt(s1[1]);
            for(j = i + 1;j < transactions.length;j++){
                String s2[] = transactions[j].split(",");
                int k2 = Integer.parseInt(s2[1]);
                if(s2[0].equals(s1[0]) && !(s2[3].equals(s1[3])) && Math.abs(k1 - k2) <= 60 ){
                    if(!li.contains(transactions[i]))
                        li.add(transactions[i]);
                    if(!li.contains(transactions[j]))
                        li.add(transactions[j]);
                }
            }
        }
        return li;
    }
}
```
