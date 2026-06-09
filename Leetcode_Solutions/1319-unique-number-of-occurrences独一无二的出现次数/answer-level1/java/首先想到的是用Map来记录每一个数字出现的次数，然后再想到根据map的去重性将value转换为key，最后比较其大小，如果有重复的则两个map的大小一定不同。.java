### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        
		if(null == arr) {
			return false;
		}
		
		Map<Integer,Integer> map = new HashMap<Integer,Integer>();
		Map<Integer,Integer> res = new HashMap<Integer,Integer>();
		int tmp = 0;
		int val = 0;
		for(int i=0; i<arr.length;i++) {
			tmp = arr[i];
			
			if(null == map.get(tmp)) {
				map.put(tmp, 1);
			}else {
				val = map.get(tmp);
				map.put(tmp, val+1);
			}
		}
		int size = map.size();
		
		for(Map.Entry<Integer, Integer> entry:map.entrySet()) {
			res.put(entry.getValue(), 1);
		}
		
		return size==res.size()?true:false;
	
    }
}
```