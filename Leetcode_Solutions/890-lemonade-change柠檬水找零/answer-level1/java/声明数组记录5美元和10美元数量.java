
![2020011301.PNG](https://pic.leetcode-cn.com/07cb38bdfc526c73dac2e3ec9cf23436437de653cd69b08ae0ff8d1fc00d3d7b-2020011301.PNG)
### 解题思路
因为只有三种币:5美元,10美元,20美元;5美元不用找零,10美元只能从5美元中找零,
20美元可以从(10+5)美元方案中找零,或者20美元从(5+5+5)美元方案中找零. 
为了贪心,出现20美元时,优先从(10+5)美元方案找零.
声明一个长度为11的credit数组,记录5美元[数组下标对应为5]和10美元[数组下标对应为10]的数量,
遇到10美元,对credit[5]--;credit[10]++;再判断credit[5]是否小于0,小于0则返回false;
遇到20美元,对credit[5]--,并且credit[10]--;或者credit[5]-=3,再判断credit[5]是否小于0,小于0则返回false;
### 代码

```java
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int[] credit = new int[11];
    	for(int i = 0;i<bills.length;i++) {
    		if(bills[i]==5) {
    			credit[5]++;
    		}else if(bills[i]==10) {
    			credit[5]--;
    			credit[10]++;
    			if(credit[5]<0) {
    				return false;
    			}
    		}else {
    			if(credit[10]>0) {
    				credit[10]--;
    				credit[5]--;
    				if(credit[5]<0) {
    					return false;
    				}
    			}else {
    				credit[5] -=3;
    				if(credit[5]<0) {
    					return false;
    				}
    			}
    		}
    	}
        return true;
    }
}
```