### 解题思路
本人是底层的南大cs小白，在家刷刷题练练技术，这个题理不清楚坑就会很多。以下是我解题的苦逼过程：
我从回文串的定义出发，发现回文串都是对称结构，轴对称！妥了，我马上想到从1开始到字符串前一个截至，以它们为轴，遍历其两侧字符串，判断两侧是否一样，代码写完了发现ffffffggggg这个例子没过，mmp，我思考了一下原因，发现我的算法只能输出fffff，于是我就准备暴力一波，发现超时了，暴力需要3层循环，时间复杂度确实高，后来我想过用滑动窗口滚着查找，后来感觉麻烦放弃了。
之后，我想这把字符串倒转过来，然后找一个最大的公共子串，于是掏出了动态规划方法，后来提交又撞坑了，心态有点炸，之后我回想我的第一个解法，发现aaaa，这种，需要从aa，aa这么开始判断，于是我又想到了补空格，然后最后删了，这不就稳了嘛，后来一想，万一坑爹测试数据有空格咋办，还是增加轴的个数吧，我最后选择了小数，用 double p表示，每次增加0.5，然后根据p值判断轴两边的起始比较位置。这回ac了。我觉得这个想法最简单，适合初学者。

总结一下就是：1.暴力法慎用。2.边界条件要考虑清楚，由特殊到一般。3.求最长公共子串和子序列等字符串操作算法应该好好学习一下。

### 代码

```java
class Solution {
  
   public static String longestPalindrome(String s) {
		if(s.length() == 0 | s.length() == 1){
			return s;
		}
		else if(s.length() == 2){
			return s.substring(0,1).intern() == s.substring(1,2).intern() ? s: s.substring(0,1);
		}
		else{
			String r = new String();
			String t = new String();
			int i,j; 
			double p; // 中点
			for(p = 0.5; p < s.length() - 1; p += 0.5){
				if( (int) p == p ) // 判断p的值是否为2.0，3.0这种
                {
					i = (int)(p - 1);
					j = (int)(p + 1);
				}
				else{
					i = (int)(p - 0.5);
					j = (int)(p + 0.5);
				}
				while( i >= 0 && j < s.length()){
					if(s.charAt(i) == s.charAt(j)){
						t = s.substring(i, j+1);
						i--; j++;
					}
					else{
						break;
					}
				}
				if(t.length() > r.length()){
					r = t;
				}
			} 
			if(r.length() == 0){
				r = s.substring(0, 1);
			}
	        return r;
		}
    }

}
```