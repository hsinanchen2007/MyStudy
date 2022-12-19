个人理解哈
二分法 ： 结果集是有序的 答案是随机的 
循环 缩小边界 找到结果
考虑边界问题

这是我写的第二题二分查找题目，使用还不成熟
欢迎提出建议，一起努力
```
public int mySqrt(int x) {
		//就怕这种0,1 先给他撸上
        if(x == 1 || x==0){
            return x;
        }

        long left = 0;// 左边界   用int会报超时，估计是测试数据太大，导致溢出报错
		long right = x;// 右边界
		long middle = (left + right) / 2;// 中间 中数=(大+小)/2
		boolean b = true;//作为一个判断标志

		while (b) {//while 循环用于不确定的循环次数

			if (middle * middle > x) {// 中间值的平方大了
				right = middle;// m的平方大于x,把中间值作为右边界,右边界从右挪到中间
			} else {
				left = middle;// m的平方大于x,把中间值作为左边界
			}

			//把中间点重新定义，如果：left=3 right=4 middle=3(除号/向下取整),所以会偏向小的值
			middle = (left + right) / 2;
			if (middle == right || middle == left) {
				b = false;
			}
		}
		return (int)middle;
    }
```
当然一瞬间我想到的是,哈哈哈哈hhhh
```
public static int mySqrt(int x) {
		
		return (int)Math.sqrt(x);
	}
```
