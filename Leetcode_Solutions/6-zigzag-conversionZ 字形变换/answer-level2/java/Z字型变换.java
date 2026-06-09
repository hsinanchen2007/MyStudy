### 解题思路
此处撰写解题思路
执行用时 :35 ms, 在所有 Java 提交中击败了13.11% 的用户
内存消耗 :42.3 MB, 在所有 Java 提交中击败了5.12%的用户

强行变换二维数组,循环拼接,这个方法我自己都看不下去了
### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
    	if(numRows==1){
    		return s;
    	}else{
    		// 每层最大长度
    		int allLength = (s.length()/(numRows*2-2))*(numRows-1) + (s.length()%(numRows*2-2) < numRows ? 1:s.length()%(numRows*2-2)-numRows+1);
    		char z[][] = new char[numRows][allLength];
    		for(int i=0;i<s.length();i++){
    			int tempi = i%(numRows*2-2) < numRows ? i%(numRows*2-2) : (2*(numRows-1)-i%(numRows*2-2));
    			int tempj = (i/(numRows*2-2))*(numRows-1) + ((i%(numRows*2-2) < numRows ? 0:i%(numRows*2-2)-numRows+1));
    			z[tempi][tempj] = s.charAt(i);
    		}
    		StringBuilder zs = new StringBuilder(s.length());
    		for(int i=0;i<z.length;i++){
    			for(int j=0;j<z[i].length;j++){
    				if(z[i][j] != 0){
    					zs.append(z[i][j]);
    				}
    			}
    		}
    		return zs.toString();
    	}
    

    }
}
```