最简单的方法当然是穷举啦~穷举算法如下：
public static  int CountDigitOne(int n) {
	int count=0;
	for(int i=1;i<n;i++) {
		int b=i;
		while (b>0) {
			if(b%10==1) {
				count++;
			}
			b=b/10;
		}
	}
	return count;
}


优点是比较简单，弊端很明显，当数字大于100的时候，计算就会非常的慢，甚至超时。

那么就采用另一个方法，利用排列组合的方法求解。比如说1234，那么最大位数是1，那么很明显0~999的数字全部都可以算在里面；如果最高位数是2，就是说0~999，1000~1999中的1都可以算在里面。这里就涉及到一个判断，即最大位大于1的话，是包含了1000~1999所有的数字的，那么在0~999中的1全部加起来再乘2之后，还需要再加上1000；而千位是1的话就只需要加上后面的234。算完千位的贡献之后再看百位的贡献，同上。然后再看十位和个位。
   算法：首先计算一共有几位数，然后从高位往低位依次计算，代码如下：
public static void main(String[] args) {
		countDigitOne(20);
	}
	public static  int countDigitOne(int n) {
		int a=0;
		int len=0;
		int b=n;
		int value=0;
		while (n>0) {
			len++;
			n=n/10;
		}
		n=b;
		int [] nums=new int[len];
		//实现排列组合
		for(int i=0;i<len;i++) {
			nums[i]=n%10;
			n=n/10;
		}
		n=b;
		while(len>1) {
			double pai1=1;
			value=0;
			for(int i=1;i<len;i++) {
				pai1=1;
				
				for(int j=0;j<i;j++) {
			pai1=pai1*(len-1-j)/(j+1);
			
					}
				
				value=(int)Math.pow(9, len-1-i)*(int)pai1*i+value;
				//System.out.println(value);
			}
		len--;
		b=len;
		n=n%(int)Math.pow(10, b);
		a=a+nums[b]*value;
			if(nums[b]>1) {
				a=a+(int)Math.pow(10, b);
			}else if(nums[b]==1) {
				a=a+n+1;
			}
		}
		if(n>0) {
			a=a+1;
		}
		System.out.println(a);
		return a;
	}
	
}

