### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public boolean lemonadeChange(int[] bills) {
        int sum5=0;
        int sum10=0;
        int sum20=0;
        for(int i=0;i<bills.length;i++) {
        	if(bills[i]==5) {
        		sum5+=5;
        	}
        	else if(bills[i]==10) {
        		sum5-=5;
        		if(sum5>=0) {
        			sum10+=10;
        		}else {
        			return false;
        		}
        	}else {
        		if(sum5-5>=0&&sum10-10>=0) {
        			sum5-=5;
        			sum10-=10;
        			sum20+=20;
        		}
        		else if(sum5-15>=0) {
        			sum5-=15;
        			sum20+=20;
        		}
        		else {
        			return false;
        		}
        	}
        }
        return true;
    }
}
```