![2020021201.PNG](https://pic.leetcode-cn.com/7971ba084ae75afe0ab3b4605f070cdd86be148938a172b482e72d55278c8e62-2020021201.PNG)

### 解题思路
//先遍历一遍字符串,声明哈希表recMap记录字母出现次数,key为字母,value为出现次数
//再遍历一遍哈希表recMap,维护两个单调栈letCount(按照字母出现次数单调递增),letter(根据字母出现次数单调递增给字母排序)
//最后再使元素出栈,声明out记录拼接排序后的字符串,输出out;

### 代码

```java
class Solution {
    public String frequencySort(String s) {
//先遍历一遍字符串,声明哈希表recMap记录字母出现次数,key为字母,value为出现次数
    	Map<Character,Integer> recMap = new HashMap<>();
    	for(char ch:s.toCharArray()) {
    		if(!recMap.containsKey(ch)) {
    			recMap.put(ch, 1);
    		}else {
    			recMap.put(ch, recMap.get(ch)+1);
    		}
    	}
        Deque<Character> letter = new LinkedList<>();
        Deque<Character> letter1 = new LinkedList<>();
        Deque<Integer> letCount1 = new LinkedList<>();
        Deque<Integer> letCount = new LinkedList<>();
//再遍历一遍哈希表recMap,维护两个单调栈letCount(按照字母出现次数单调递增),letter(根据字母出现次数单调递增给字母排序)
        for(char ch:recMap.keySet()) {
        	if(letCount.peek()==null) {
        		letCount.push(recMap.get(ch));
        		letter.push(ch);
        	}else {
        		if(recMap.get(ch)>=letCount.peek()) {
        			letCount.push(recMap.get(ch));
        			letter.push(ch);
        		}else {
        			while((recMap.get(ch)<letCount.peek())) {
        				letCount1.push(letCount.pop());
        				letter1.push(letter.pop());
        				if(letCount.peek()==null||recMap.get(ch)>=letCount.peek()) {
        					letCount1.push(recMap.get(ch));
        					letter1.push(ch);
        					break;
        				}
        			}
        			while(letCount1.peek()!=null) {
        				letCount.push(letCount1.pop());
        				letter.push(letter1.pop());
        			}
        		}
        	}
        }
//最后再使元素出栈,声明out记录拼接排序后的字符串,输出out;
        String out="";
        while(letCount.peek()!=null) {
        	char temp = letter.pop();
        	int num = letCount.pop();
        	for(int i=0;i<num;i++) {
        		out += temp;
        	}
        }
    	return out;
    }
}
```