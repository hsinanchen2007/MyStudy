### 解题思路：
步骤一：用一个 $hashmap$ 存放数字出现的次数
步骤二：然后对 $hashmap$ 的 $value$ 进行降序排序
步骤三：比较 $key$ 和 $value$ 是否相等，相等则返回
```java
class Solution {
	 public int findLucky(int[] arr) {
		 //步骤一：用一个hashmap存放数字出现的次数
		 HashMap<Integer, Integer> h=new HashMap<>();
		 for (int i = 0; i < arr.length; i++) {
			if (h.get(arr[i])==null) {
				h.put(arr[i], 1);
			} else {
				h.put(arr[i], h.get(arr[i])+1);
			}
		 }
		 //然后对hashmap的value进行排序，降序
		 Set<Entry<Integer, Integer>> keySet = h.entrySet();
		 List<Map.Entry<Integer, Integer>> infoIds = new ArrayList<>(keySet);
		 Collections.sort(infoIds, new Comparator<Map.Entry<Integer, Integer>>() {
				@Override
				public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
					return (o2.getValue() - o1.getValue());

					
				}
			});
		 //比较key和value是否相等，相等则返回
		 int a=0;
		 for (int i = 0; i < infoIds.size(); i++) {
	           
	            for (int j = 0; j < infoIds.get(i).getValue(); j++) {
	            	if (infoIds.get(i).getValue()==infoIds.get(i).getKey()) {
						return infoIds.get(i).getKey();
					}
				}
	            
	    }
		return -1;
	    }
}
```
