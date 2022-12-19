# **强行一行代码，强行pythonic.**
```
class Solution {
	public static double angleClock(int hour, int minutes) {
	return (double) Math.min((Math.abs((double)((double)hour*30+(double)minutes/2)-6*(double)minutes)),360-(Math.abs((double)((double)hour*30+(double)minutes/2)-6*(double)minutes)));
}
}
```
