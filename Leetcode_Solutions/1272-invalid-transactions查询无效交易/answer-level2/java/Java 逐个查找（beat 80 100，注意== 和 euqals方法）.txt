- 先切分，放在数组类型的列表里，依次取出使用
- 要建立是否已经放置该表项的布尔数组，进行控制
- 注意！！！判断的时候 == 和 euqals方法的区别！！！
-  ！！ “==” 比较的是两个引用在内存中指向的是不是同一对象（即同一内存空间），也就是说在内存空间中的存储位置是否一致。
-  ！！ equals方法比较的是内存空间存放的数据是否相同

```
class Solution {
    public List<String> invalidTransactions(String[] transactions) {
        int nums = transactions.length;
        List<String[]> storge  = new ArrayList<>();
        List<String> result = new ArrayList<>();
        boolean []AlreadyPut  = new boolean[nums];
        String name  = "";
        String city = "";
        int time = 0;
        
        
        for(int i=0;i<nums;i++)
        {
            String [] afterSplit = transactions[i].split(",");
            storge.add(afterSplit);
            AlreadyPut[i] = false;
        }
        
        for(int i=0;i<nums;i++)
        {
            int j=i+1;
            String[] itemp = storge.get(i);
            name = itemp[0];
            city = itemp[3];
            time = Integer.parseInt(itemp[1]);
            
            
            if(Integer.parseInt(itemp[2])>1000 && AlreadyPut[i] == false)
            {
                result.add(transactions[i]);
                AlreadyPut[i] = true;
            }
            
            for(;j<nums;j++)
            {
                String[] jtemp = storge.get(j);

                
                if(name.equals(jtemp[0])==true && Math.abs(time- Integer.parseInt(jtemp[1]))<=60 && city.equals(jtemp[3])==false)
                {
                    if(AlreadyPut[j] == false)
                    {
                        result.add(transactions[j]);
                        AlreadyPut[j] = true;
                    }

                    if(AlreadyPut[i] == false)
                    {
                        result.add(transactions[i]);
                        AlreadyPut[i] = true;
                    }
                }
            }
        }
        
        return result;
    
    }
}
```

