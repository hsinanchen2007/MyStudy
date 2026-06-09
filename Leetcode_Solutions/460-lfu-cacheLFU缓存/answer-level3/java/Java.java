### 解题思路
此处撰写解题思路

### 代码

```java
class LFUCache {

   public int capacity;//容量大小
	public HashMap<Integer, Integer> map = new HashMap<>();//存储put进去的key和value
	public HashMap<Integer, Integer> frequent = new HashMap<>();//存储每个key的频率值
	//存储每个频率的相应的key的值的集合，这里用HashSet是因为其是由HashMap底层实现的，可以O(1)时间复杂度查找元素
	//而且linked是有序的，同一频率值越往后越最近访问
	public HashMap<Integer, LinkedHashSet<Integer>> list = new HashMap<>();
	int min = -1;//标记当前频率中的最小值
	
    public LFUCache(int capacity) {
        this.capacity = capacity;
    }
    
    
    public int get(int key) {
    	if(!map.containsKey(key)){
    		return -1;
    	}else{
    		int value = map.get(key);//获取元素的value值
    		int count = frequent.get(key);
    		frequent.put(key, count + 1);
    		
    		list.get(count).remove(key);//先移除当前key
    		
    		//更改min的值
    		if(count == min && list.get(count).size() == 0)
                min++;
    		
    		LinkedHashSet<Integer> set = list.containsKey(count + 1) ? list.get(count + 1) : new LinkedHashSet<Integer>();
    		set.add(key);
			list.put(count + 1, set);
    		
    		return value;
    	}
    	
    }
    
    public void put(int key, int value) {
    	if(capacity <= 0){
    		return;
    	}
    	//这一块跟get的逻辑一样
    	if(map.containsKey(key)){
    		map.put(key, value);
    		int count = frequent.get(key);
    		frequent.put(key, count + 1);
    		
    		list.get(count).remove(key);//先移除当前key
    		
    		//更改min的值
			if (count == min && list.get(count).size() == 0)
				min++;
    		
    		LinkedHashSet<Integer> set = list.containsKey(count + 1) ? list.get(count + 1) : new LinkedHashSet<Integer>();
    		set.add(key);
			list.put(count + 1, set);
    	}else{
    		if(map.size() >= capacity){
    			Integer removeKey = list.get(min).iterator().next();
        		list.get(min).remove(removeKey);
        		map.remove(removeKey);
        		frequent.remove(removeKey);
        	}
    		map.put(key, value);
    		frequent.put(key, 1);
    		LinkedHashSet<Integer> set = list.containsKey(1) ? list.get(1) : new LinkedHashSet<Integer>();
    		set.add(key);
    		list.put(1, set);
    		
    		min = 1;
    	}
    	
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```