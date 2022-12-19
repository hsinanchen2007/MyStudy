class Solution {
    public int reverse(int x) {
       int ans = 0;//保存运算结果
		while (x != 0) {
			int pop = x % 10;//对10取余得到末位数字

			try {
		
				int temp=Math.multiplyExact(ans, 10);//完成ans*10，可能溢出抛出异常
				ans = Math.addExact(temp, pop);//完成ans*10+pop,可能溢出抛出异常
			} catch (ArithmeticException e) {//捕获异常直接将ans置零跳出循环
				// TODO: handle exception
				ans = 0;
				break;
			}
			x /= 10;
		}
		return ans;
    }

}
解题思路 通过取模运算依次不断取出当前数字的末位数，然后累加。还有要解决判断整数溢出这个问题，可以利用java的异常机制解决，调用Math类的加法和乘法函数完成运算，一旦溢出就会抛出异常，
直接捕获异常然后ans赋值为0即可，非常方便。