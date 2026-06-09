![2020011601.PNG](https://pic.leetcode-cn.com/a4f089facae9f38d43c24cec04c8ad33ddf1ca61d273542083f38934cdedbb4f-2020011601.PNG)

### 解题思路
//用nameMap记录交易名称,nameMap中的Key为交易在数组transanctions中的索引,Value为交易名称
//用timeMap记录交易时间,timeMap中的Key为交易在数组transanctions中的索引,Value为交易时间
//用cityMap记录交易城市,cityMap中的Key为交易在数组transanctions中的索引,Value为交易城市
//用boolean型put数组记录无效交易是否被添加在out中(避免重复添加相同的无效交易记录),
//put数组初始为false,当某个交易被添加到out中时,该交易在put中对应索引的值改为true.
### 代码

```java
class Solution {
    public List<String> invalidTransactions(String[] transactions) {
    	int len = transactions.length;
        List<String> out = new ArrayList<>();
        boolean[] put = new boolean[len];
        Map<Integer,String> nameMap = new HashMap<>();
        Map<Integer,String> timeMap = new HashMap<>();
        Map<Integer,String> cityMap = new HashMap<>();
        int i =0;
        while(i<len) {
        	String[] midList = transactions[i].split(",");
        	nameMap.put(i, midList[0]);
        	timeMap.put(i, midList[1]);
        	cityMap.put(i, midList[3]);
        	put[i] = false;
        	if(Integer.valueOf(midList[2])>1000) {
        		out.add(transactions[i]);
        		put[i] = true;
        	}
        	i++;
        }
        for(int k =0;k<len-1;k++) {
        	for(int m =k+1;m<len;m++) {
        		if(nameMap.get(k).equals(nameMap.get(m))) {
        			if(!cityMap.get(k).equals(cityMap.get(m))) {
        				if(Math.abs(Integer.valueOf(timeMap.get(k))-Integer.valueOf(timeMap.get(m)))<=60) {
        					if(put[k]==false) {
        						out.add(transactions[k]);
        						put[k] = true;
        					}
        					if(put[m]==false) {
        						out.add(transactions[m]);
        						put[m] = true;
        					}
        				}
        			}
        		}
        	}
        	
        }
        return out;
    }
}
```