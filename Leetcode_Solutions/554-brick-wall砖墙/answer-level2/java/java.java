### 解题思路

### 代码

```java
class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        
		//map集合key为各行能达到的所有长度，value为该长度的数量
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < wall.size(); i++) {
        	int width = 0;
			for (int j = 0; j < wall.get(i).size()-1; j++) {
				width += wall.get(i).get(j);
				if (map.get(width) != null) {
					map.replace(width, map.get(width)+1);
				}else {
					map.put(width, 1);
				}
			}
		}
        //将所有长度出现次数放入list，遍历list，获得最大次数，总高度减最大次数即为最少需要穿过的层数
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (Integer integer : map.values()) {
			list.add(integer);
		}
		if (list.size() == 0) {
			return wall.size();
		}
		int count=list.get(0);
		for (int i = 0; i < list.size(); i++) {
			if (count < list.get(i)) {
				count = list.get(i);
			}
		}
		return wall.size()-count;
    
    
    }
}
```