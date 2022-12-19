![2020021001.PNG](https://pic.leetcode-cn.com/1f00ab6b2e81eb5a2d65b96e74320aee9e5e08b5aaebfb5b6a22570387276cfa-2020021001.PNG)

### 解题思路
//声明cnt记录操作次数;
//先用整数num对2取余,若余数等于0,cnt++;若余数不等于0,cnt+=2;
//更新num---num=num/2;
//最后返回cnt;

### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
        int cnt = 0;
        int mod=0;
        while(num!=1) {
        	mod=num%2;
        	if(mod!=0) {
        		cnt+=2;
        	}else {
        		cnt+=1;
        	}
        	num=num/2;
        }
        cnt++;
    	
    	return cnt;
    }
}
```