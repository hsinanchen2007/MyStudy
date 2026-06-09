### 解题思路
1.IV可表示为后一个减去前一个，即-1+5=4
2.所以，依次遍历，遇到前一个数的值小于后一个的，就sum减去前一个
3.注意!!!，sum只加了pre前一个，所以最后要加上最后一个数
### 代码

```java
class Solution {
    public int romanToInt(String s) {
    	int sum=0;
    	int pre=getValue(s.charAt(0));
         for (int i = 1; i <s.length();i++) {
			
    		if (pre>=getValue(s.charAt(i))) {
				sum+=pre;
			}
    		else  {
    			sum-=pre;
			}
    		pre=getValue(s.charAt(i));
		}
		
		sum=sum+pre;
		return sum;
    }
    
    private int getValue(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
}

```