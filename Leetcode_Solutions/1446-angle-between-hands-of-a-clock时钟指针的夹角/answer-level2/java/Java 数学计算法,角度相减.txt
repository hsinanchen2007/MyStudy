### 解题思路
注意角度有小数

### 代码

```java
class Solution {
    public double angleClock(int hour, int minutes) {
        double hh = hour;
    	hh*=30;
    	hh+=30*((double)minutes/60);

        hh %=360;
        minutes*=6;
       
        if(Math.abs(hh-minutes)>180) {
        	return 360-Math.abs(hh-minutes);
        }
        return Math.abs(hh-minutes);
    
    }
}
```