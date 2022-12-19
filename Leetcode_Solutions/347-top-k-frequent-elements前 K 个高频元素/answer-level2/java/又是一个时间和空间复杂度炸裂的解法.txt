![2020021202.PNG](https://pic.leetcode-cn.com/481e92e5ce2143ce640fc8941f459c84eb96ac1e46b69f87ab24c04c5a21ebc3-2020021202.PNG)

### 解题思路
//通过维护两个单调栈来对数字出现的频率进行排序

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> out = new ArrayList<>();
        Map<Integer,Integer> recMap = new HashMap<>();
        for(int i =0;i<nums.length;i++) {
        	if(!recMap.containsKey(nums[i])) {
        		recMap.put(nums[i], 1);
        	}else {
        		recMap.put(nums[i], recMap.get(nums[i])+1);
        	}
        }
        Deque<Integer> num = new LinkedList<>();
        Deque<Integer> num1=new LinkedList<>();
        Deque<Integer> count=new LinkedList<>();
        Deque<Integer> count1=new LinkedList<>();
        for(int in:recMap.keySet()) {
        	if(count.peek()==null) {
        		count.push(recMap.get(in));
        		num.push(in);
        	}else {
        		if(recMap.get(in)>=count.peek()) {
        			count.push(recMap.get(in));
        			num.push(in);
        		}else {
        			while(recMap.get(in)<count.peek()) {
        				count1.push(count.pop());
        				num1.push(num.pop());
        				if(count.peek()==null) {
        					count1.push(recMap.get(in));
        					num1.push(in);
        					break;
        				}
        				if(recMap.get(in)>=count.peek()) {
        					count1.push(recMap.get(in));
        					num1.push(in);
        					break;
        				}
        			}
        			while(count1.peek()!=null) {
        				count.push(count1.pop());
        				num.push(num1.pop());
        			}
        		}
        	}
        }
        for(int i=0;i<k;i++) {
        	out.add(num.pop());
        }
        return out;
    }
}
```