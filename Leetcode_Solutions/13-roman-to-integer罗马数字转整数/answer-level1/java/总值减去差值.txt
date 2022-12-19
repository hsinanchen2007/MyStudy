### 解题思路
其实好多评论区的代码都没有读懂。就自己瞎合计了一下，结果击败Java的5%用户（笑哭）；
该问题唯一的坎儿就在于I可以放在V，X的左面；X可以放在L,C的左面；C可以放在D，M的左面；且代表不同的数字
那么我是这么想的，IV和IX代表4和9，如果没有这个规则那么IV和IX代表6和10；同理
XL,CX代表60和110；CD,CM代表600和1100；
那我就按照没有那个坎来算个总数，最后减去差值就可以了（2,20,200）。

### 代码

```java
class Solution {
    public int romanToInt(String a) {
int n = 0;
    	int m = 0;
    	System.out.println(a.contains("XC"));
    	if(a.contains("IV")||a.contains("IX")){
    		n = n+2;
    	}
    	if(a.contains("XL")||a.contains("XC")){
    		n = n+20;
    	}
    	
    	if(a.contains("CM")||a.contains("CD")){
    		n = n+200;
    	}
    	char[] arr = a.toCharArray();
    	System.out.println(n);
    	HashMap<Character, Integer> map = new HashMap<Character, Integer>();
    	map.put('I', 1);
    	map.put('V', 5);
    	map.put('X', 10);
    	map.put('L', 50);
    	map.put('C', 100);
    	map.put('D', 500);
    	map.put('M', 1000);
    	for (int i = 0; i < arr.length; i++) {
    		m = map.get(arr[i]) + m;
		}
    	return m-n;
    }
}
```