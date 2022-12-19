```
class Solution {
    public List<String> invalidTransactions(String[] transactions) {
        List<String[]> list = new ArrayList<>();
        for(int i = 0; i < transactions.length; i++)
            list.add(transactions[i].split(","));
        
        HashSet<String> set = new HashSet<>();
        for(int i = 0; i < list.size(); i++)
        {
            if(set.contains(transactions[i]))
                continue;
            String[] s1 = list.get(i);
            if(Integer.valueOf(s1[2]) > 1000)
            {
                set.add(transactions[i]);
                continue;
            }
            for(int j = 0; j < transactions.length; j++)
            {
                if(j == i)
                    continue;
                String[] s2 = list.get(j);
                if(s1[0].equals(s2[0]))
                {
                    if(Math.abs(Integer.valueOf(s2[1]) - Integer.valueOf(s1[1])) <= 60 && !s1[3].equals(s2[3]))
                    {
                        set.add(transactions[i]);
                        set.add(transactions[j]);
                    }
                }
            }
        }
        return new ArrayList<>(set);
    }
}
```
