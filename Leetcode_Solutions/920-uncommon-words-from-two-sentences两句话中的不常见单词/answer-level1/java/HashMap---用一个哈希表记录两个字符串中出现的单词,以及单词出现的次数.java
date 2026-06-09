![2019122401.PNG](https://pic.leetcode-cn.com/c28c4629131bf53e58bedf921c054895fea9ab722fc5b6f298c760ac1aa890bd-2019122401.PNG)
### 解题思路
先分别遍历String A 和String B,
用一个哈希表(myHash)记录String A和B中出现的单词和单词出现的次数(出现的单词为Key,单词出现的次数为Value)
再遍历一遍哈希表,将出现次数为1的单词作为结果记录下来,并返回
### 代码
```java
class Solution {
    public String[] uncommonFromSentences(String A, String B) {
    	int count = 0;
    	String[] myRes = new String[A.length()+B.length()];
    	String[] myA = new String[A.length()];
    	myA = A.split(" ");
    	String[] myB = new String[B.length()];
    	myB = B.split(" ");
    	Map<String,Integer> myHash = new HashMap<>();
    	for(int i = 0;i<myA.length;i++) {
    		if(!myHash.containsKey(myA[i])) {
    			myHash.put(myA[i], 1);
    		}else if(myHash.containsKey(myA[i])) {
    			myHash.put(myA[i], myHash.get(myA[i])+1);
    		}
    	}
    	for(int i = 0;i<myB.length;i++) {
    		if(!myHash.containsKey(myB[i])) {
    			if(!myHash.containsKey(myB[i])) {
    				myHash.put(myB[i], 1);
    			}
    		}else if(myHash.containsKey(myB[i])) {
    			myHash.put(myB[i], myHash.get(myB[i])+1);
    		}
    	}
    	Iterator myIter = myHash.entrySet().iterator();
    	while(myIter.hasNext()) {
    		Map.Entry entry = (Map.Entry) myIter.next();
    		Object val = entry.getValue();
    		if((int)val==1) {
    			myRes[count] = (String)entry.getKey();
    			count++;
    		}
    	}
    	String[] res = new String[count];
    	System.arraycopy(myRes, 0, res, 0, count);
    	return res;
    }
}
```