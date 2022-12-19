
```
class Solution {
    public List<String> invalidTransactions(String[] transactions) {

        Set<String> list = new HashSet<>();//定义set不必担心插入元素重复问题

        for (int i = 0; i < transactions.length; i++) {//首先开启一个for循环遍历transactions
            String[] split = transactions[i].split(",");
            int integer = Integer.parseInt(split[2]);
            if (integer > 1000) {       //csv解析，提取出价格项，大于1000 直接放set中
                list.add(transactions[i]);
            }
            for (int j = i+1; j < transactions.length; j++) {  
//开启第二个for循环，其中j=i+1，用于比较当前元素与之后元素间关系
                String[] splitj = transactions[j].split(",");
                if (split[0].equals(splitj[0]) &&
                        !split[3].equals(splitj[3]) &&
                        Math.abs(Integer.parseInt(split[1]) - Integer.parseInt(splitj[1])) <= 60) {
//&&并列出三个条件，第一条名称相同，第二天不同城市，第三条时间在60内以及60
                    list.add(transactions[i]);
                    list.add(transactions[j]);
//将比较的两条都放入无效交易set中
                }
            }
        }
        return new ArrayList(list);//set转为list返回
    }
}
```
