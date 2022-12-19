### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int romanToInt(String romanNum) {
         
		
		Map<String, Integer> romanMap = new HashMap<String, Integer>();
		romanMap.put("I", 1);
		romanMap.put("V", 5);
		romanMap.put("X", 10);
		romanMap.put("L", 50);
		romanMap.put("C", 100);
		romanMap.put("D", 500);
		romanMap.put("M", 1000);
		
		

		int result = 0;  
		int first = 0;
		int second = 0;

		for(int i=0;i<romanNum.length()-1;i++){
			first = romanMap.get(String.valueOf(romanNum.charAt(i)));
			second = romanMap.get(String.valueOf(romanNum.charAt(i + 1)));
			
			if(first >= second){
				result += first;
			}else {
				result -= first;
			}
		}
		System.out.println(String.valueOf(romanNum.charAt(romanNum.length() - 1)));
		
		result += romanMap.get(String.valueOf(romanNum.charAt(romanNum.length() - 1)));

		return result;
    }
}
```