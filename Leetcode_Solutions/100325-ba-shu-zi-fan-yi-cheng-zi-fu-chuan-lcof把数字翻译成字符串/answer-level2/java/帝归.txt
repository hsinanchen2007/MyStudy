### 解题思路
排列组合问题，我觉得肯定是用到递归来求解，设计的算法流程如下：
1.设置一个计数器c；
2.对输入整数 n，将其转换为String类型；
3.判断其长度，如果空，则返回当前c的值，如果为1，则返回++c。
4.如果长度为2，我们也直接进行判断，截取前2位，转换回整数，判断var是否<=25，
满足的话，说明有2个，计数器c加2，返回c值。
5.如果长度3个以上，也是截取前2位，转换为整数，判断var的值是否小于等于25，
满足的话，递归调用函数本身，来求解从第3位开始的字符串。
然后更新字符串，丢弃字符串第一位数字，继续求解从第2位开始的字符串。
（解释：相当于把第一位单飞，求解剩余的排列组合）

### 代码

```java
class Solution {
    
    int c = 0 ; //计数器
    
    public int cov(int n)
	{
		String s = String.valueOf(n);
		if(s.isEmpty())  // 空了
		{
			return c;
		}
		else if(s.length() == 1)  // 有一个
		{
			return ++c;
		}
		else if(s.length() == 2)  // 有2个
		{
			int var = Integer.valueOf(s.substring(0, 2));
			if(var <= 25)
			{
				c = c + 2;
				return c;
			}
			else
			{
				return ++c;
			}
		}
		else  // 三个以上
		{
			int var = Integer.valueOf(s.substring(0, 2));
			if(var <= 25)
			{
				int t = Integer.valueOf(s.substring(2)); 
				cov(t);
			}
			s = s.substring(1); // 更新字符串
			int g = Integer.valueOf(s);
			return cov(g);
		}
    }
    public int translateNum(int num) {
        cov(num);
        return c; 
        
    }
}
```