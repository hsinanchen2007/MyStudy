### 解题思路
主要就是利用二分法减少迭代次数

### 代码

```java
class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int sum =0;//元素和
		int max =0;//最大元素
		for(int i:weights) {
			if(i>max) {
				max=i;
			}
			sum+=i;
		}
		int isum =0;
		int count =0;//计算载重为max的所需次数
		for(int i:weights) {
			isum+=i;
			if(isum>max){
				isum =i;
				count++;
			}
		}
		if(D>=count+1) {//count+1为容量为max时的需求次数，当次数大于等于该次数很显然只用返回max
			return max;
		}else if(D==1){
			return sum;
		}//后续使用二分法找出最合适的值
		int in =max ; //二分法中的较小值
		int ax =sum ;//二分法中的较大值
		while (in<ax-1) { //注意退出条件 当差距为2时判断最后一次
			if(test((in+ax)/2,weights,D)) {//平均值是能放下更新ax
				ax = (in+ax)/2;
			}else {//不成立时更新in
				in = (in+ax)/2;
			}
		}
		return ax;
    }

	private static boolean test(int m, int[] weights, int d) {
		int sum=0;
		for(int i:weights) {
			sum+=i;
			if(sum>m) {
				sum=i;
				d--;
			}
		}
		return d>0;
    }
}
```