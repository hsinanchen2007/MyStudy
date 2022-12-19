### 解题思路


### 代码

```java
public class Solution {
	// @Test
	// public void test(){
	// 	System.out.println(countAndSay(4));
	// }
	
    public static String countAndSay(int n) {
    	//定义起始串
    	String sequence = "1";
    	//每次支循环n-2次
    	for (int i = 1; i < n; i++) {
			//每计数完一个数字就更新sequence作为下一次循环的参数
    		sequence = describe(sequence.toCharArray());
		}
        return sequence;
    }
    public static String describe(char[] chars) {
		StringBuilder sb = new StringBuilder();
		int count=1;
		int index=1;
		char chCurr = chars[0];//表示当前要计数的数字
		while(index < chars.length){
			char temp = chars[index];
			//如果一样计数值就+1
			if(chCurr == temp){
				count++;
			//否则表示当前计数的数字已经结束
			//需要更新chCurr,计数值count,并将计数完成的数字存起来
			}else{
				sb.append(count);
				sb.append(chars[index-1]);
				chCurr = chars[index];
				count = 1;
			}
			index++;
		}
		//将最后一段计数结束的数字及其计数结果存起来.例如1211的11部分
		sb.append(count);
		sb.append(chars[index-1]);
        return sb.toString();
    }
}
```