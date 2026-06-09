### 解题思路
思路如下，初学者思维

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
    	int[]map=new int[26];                     //设置一个数组存放chars的字母频率
    	for (int i = 0; i < chars.length(); i++) {
			map[chars.charAt(i)-'a']++;                   
		}

    	int ans=0;                                 //设置变量储存字符串累加长度
    	for (int i = 0; i < words.length; i++) {
    		int[]arr=new int[26]; //设置一个数组存放单词的字母频率,注意：每个单词是独立的数组
			for (int j = 0; j < words[i].length(); j++) {
				arr[words[i].charAt(j)-'a']++;
			}
			boolean flag= true;                    //将两个数组比较
			for (int j = 0; j < words[i].length(); j++) { //没必要比较全部数组  
				if (map[words[i].charAt(j)-'a']<arr[words[i].charAt(j)-'a']) {
					flag=false;
					break;
				}
			}
			if (flag) {
				ans+=words[i].length();
			}
		}
		return ans;
    }
}                                                                     
```