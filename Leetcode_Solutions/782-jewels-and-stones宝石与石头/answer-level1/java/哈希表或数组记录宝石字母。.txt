![2019122402.PNG](https://pic.leetcode-cn.com/3187978530e1b3a5f718933bef716042d1a11f7edfa7c2a0d5e228e96518a658-2019122402.PNG)

### 解题思路
数组：
遍历J字符串:用数组(长度设为58,大小写字母的ASCII码从65-122,其中(91-96为标点符号))记录宝石字母,
被认为是宝石的字母,则在相应索引位置赋值为1;
遍历字符串S,若S字符串中的字符在数组中对应的索引位置的值不为0, 则说明该字母是宝石,count++(count记录宝石字母个数)
哈希表：
遍历J字符串:用哈希表记录宝石字母,Key为宝石字母,value默认为0
遍历S字符串:若S字符串的字母出现在哈哈希表的Key中,则该字母为宝石字母,count++;
### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
		//#########数组,耗时1ms,击败99.90%用户
    	int count = 0;
    	int[] table = new int[58];
    	for(int i = 0;i<J.length();i++) {
    		table[J.charAt(i)-'A']++;
    	}
    	for(int i = 0;i<S.length();i++) {
    		if(table[S.charAt(i)-'A']!=0) {
    			count++;
    		}
    	}
    	return count;
		//##########哈希表,耗时2ms,击败51.65%用户
		// int count = 0;
		// Map<Character,Integer> jewelHash = new HashMap<>();
		// for(int i = 0;i<J.length();i++) {
		// 	jewelHash.put(J.charAt(i), 0);
		// }
		// for(int i = 0;i<S.length();i++) {
		// 	if(jewelHash.containsKey(S.charAt(i))) {
		// 		count++;
		// 	}
		// }
		// return count;
    }
}
```