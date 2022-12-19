### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.Map.Entry;

class Solution {
    public int majorityElement(int[] nums) {
    Map<Integer,Integer> map = new HashMap<>();
    for(int ele:nums)
    {
        if(map.containsKey(ele))
        {
            int temp = map.get(ele);
            map.remove(ele);
            map.put(ele,++temp);
        }
        else
        {
            map.put(ele,1);
        }
    }
    for (Entry<Integer, Integer> entry : map.entrySet()) {
	    if(entry.getValue() > nums.length/2)
            return entry.getKey();
	    
    }
    return 0;
    }
   
}
```