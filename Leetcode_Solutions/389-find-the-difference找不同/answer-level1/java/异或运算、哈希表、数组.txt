### 解题思路
![2019122301.PNG](https://pic.leetcode-cn.com/0c7b54faff666b71b3b8d6086608977daaab9b7d48728d2d681a3dc4c7b63913-2019122301.PNG)

此处撰写解题思路

### 代码

```java
class Solution {
    public char findTheDifference(String s, String t) {
        //异或运算,耗时2ms
        char myChar = t.charAt(t.length()-1);
    	for(int i =0;i<s.length();i++) {
    		myChar ^= s.charAt(i);
    		myChar ^= t.charAt(i);
    	}
    	return myChar;
        // ##########
        //数组记录字母出现次数,耗时2ms
    	int[] charTable = new int[26];
    	for(int i=0;i<s.length();i++) {
    		charTable[s.charAt(i)-'a']++;
    		charTable[t.charAt(i)-'a']--;
    	}
    	charTable[t.charAt(t.length()-1)-'a']--;
    	for(int i = 0;i<t.length();i++) {
    		if(charTable[t.charAt(i)-'a']!=0) {
    			return t.charAt(i);
    		}
    	}
    	return 'a';
        //#############
        //哈希表,耗时21ms
    	Map<Character,Integer> myMap = new HashMap<>();
    	for(int i =0;i<s.length();i++) {
    		if(!myMap.containsKey(s.charAt(i))) {
    			myMap.put(s.charAt(i), 1);
    		}else if(myMap.containsKey(s.charAt(i))) {
    			myMap.put(s.charAt(i), myMap.get(s.charAt(i))+1);
    		}
    	}
    	for(int i =0;i<t.length();i++) {
    		if(myMap.containsKey(t.charAt(i))) {
    			myMap.put(t.charAt(i), myMap.get(t.charAt(i))-1);
    		}else if(!myMap.containsKey(t.charAt(i))) {
    			myMap.put(t.charAt(i), -1);
    		}
    		if(myMap.get(t.charAt(i))<0) {
    			return t.charAt(i);
    		}
    	}
    	return 'a';
    }
}
```