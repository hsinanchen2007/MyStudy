### 解题思路
使用TreeMap存储顺序为自然排序，所以循环treeMap中的每个值与上一个值比较，如果是连续的则继续，否则返回false
实现方法:
1. 将数组元素放到TreeMap中，key为元素值，value为元素出现次数
2. 计算需要遍历几次Map，即结果需要分为几组
3. 遍历Map并与上一个值比较，如果 前值=当前值-1，则 继续，否则说明值不连续返回false
当遍历取出一个值后将该值出现次数-1
当遍历Map到k时，说明第一组已经满足条件，则结果当前遍历，重新进行下次遍历

### 代码

```java
import java.util.Map.Entry;

class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        if(nums.length%k != 0) {
    		return false;
    	}
    	Integer size = 0;
    	Integer last = 0;
    	Map<Integer, Integer> map = new TreeMap<>();
    	for (int num : nums) {
			map.put(num, map.getOrDefault(num,0) +1);
		}

    	for (int i = 0; i < nums.length/k; i++) {
    		for (Entry<Integer, Integer> entry : map.entrySet()) {
        		int num = entry.getKey();
        		if(entry.getValue() <= 0) {
        			continue;
        		}
        		entry.setValue(entry.getValue()-1); 
    			if(size == 0) {
    				last  = num;
    				size ++;
    				continue;
    			}

    			if (last == num-1) {
    				last  = num;
    				size ++;
    			}else {
    				return false;
    			}
    			
    			if (size == k) {
    				size = 0;
    				break;
    			}
    			
    		}
		}
    	
		return true;
    }
}
```