### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int rotatedDigits(int N) {
        int count=0;
		for(int i=1;i<=N;i++){
			String s=String.valueOf(i);
			if(s.contains("3")==false&&s.contains("4")==false&&
					s.contains("7")==false){
				if(s.contains("2")==true||s.contains("5")==true||
					s.contains("6")==true||s.contains("9")==true){
					count++;
				}
					
					
				
			}
				
		}
		return count;
    }
}
```