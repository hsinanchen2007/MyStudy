### 解题思路
//先遍历一遍数组,用哈希表记录每个数组出现的次数,
//再遍历哈希表的value(每遍历到某个value,记录该value为myValue,再将该value置换为-1),
//接着查看哈希表中的value是否包含myValue;
//若包含myValue,则返回false;否则返回true.

### 代码

```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer,Integer> myHashMap = new HashMap<>();
        for(int i = 0;i<arr.length;i++) {
    		if(!myHashMap.containsKey(arr[i])) {
    			myHashMap.put(arr[i], 1);
    		}else if(myHashMap.containsKey(arr[i])) {
    			myHashMap.put(arr[i], myHashMap.get(arr[i])+1);
    		}
    	}
    	Iterator myIterator = myHashMap.entrySet().iterator();
    	while(myIterator.hasNext()) {
    		Map.Entry entry = (Map.Entry) myIterator.next();
    		Object myVal = entry.getValue();
    		Object myKey = entry.getKey();
    		myHashMap.replace((int)myKey, -1);
    		if(myHashMap.containsValue(myVal)) {
    			return false;
    		}
    	}
        return true;
    }
}
```