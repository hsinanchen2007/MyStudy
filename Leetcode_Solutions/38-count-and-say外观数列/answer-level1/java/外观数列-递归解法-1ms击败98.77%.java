### 解题思路
根据题目描述，第n项由第n-1项决定，典型的递归适用情形。用StringBuilder的append()方法往result中存元素。
时间复杂度：O（n）
空间复杂度：O（n）

### 代码

```java
class Solution {
	
	public static void main(String args[]) {
		System.out.print(countAndSay(2));
	}
    public static String countAndSay(int n) {
        if(n==1)
            return "1";
        
        String pre=countAndSay(n-1);
        StringBuilder res=new StringBuilder();
        int i=0;
        while(i<pre.length()){
            int j=i+1;
            while(j<pre.length()&&pre.charAt(i)==pre.charAt(j)){
                j++;
            }
            res.append(j-i);
            res.append(pre.charAt(i));
            i=j;
        }
        return res.toString();   
    }
}
```