![2019122302.PNG](https://pic.leetcode-cn.com/e57df62f9399edc14506780c85756f81adb9bb1bf32c9b915e295ce39434829b-2019122302.PNG)

### 解题思路
首先用哈希表记录order的字母序,出现的字母为Key,每个字母出现的顺序索引值为Value,
再遍历words数组,逐个比较数组中前后两个字符串的字典序

### 代码

```java
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        boolean active = false;
    	Map<Character,Integer> myHash = new HashMap<>();
    	for(int i=0;i<order.length();i++) {
    		myHash.put(order.charAt(i), i);
    	}
    	for(int i=0;i<words.length-1;i++) {
    		if(words[i].length()>words[i+1].length()) {
    			int j = 0;
    			while(j<words[i+1].length()) {
    				if(myHash.get(words[i].charAt(j))>myHash.get(words[i+1].charAt(j))) {
    					return false;
    				}else if(myHash.get(words[i].charAt(j))<myHash.get(words[i+1].charAt(j))) {
                        active = true;
    					break;
    				}else if(myHash.get(words[i].charAt(j))==myHash.get(words[i+1].charAt(j))) {
    					j++;
    				}
    			}
                if(!active){
                    return false;
                }
    		}else if(words[i].length()<=words[i+1].length()) {
    			int j = 0;
    			while(j<words[i].length()) {
    				if(myHash.get(words[i].charAt(j))>myHash.get(words[i+1].charAt(j))) {
    					return false;
    				}else if(myHash.get(words[i].charAt(j))<myHash.get(words[i+1].charAt(j))) {
    					break;
    				}else if(myHash.get(words[i].charAt(j))==myHash.get(words[i+1].charAt(j))) {
    					j++;
    				}
    			}
    		}
    	}
        return true;
    }
}
```