
### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
		int left,right;
		int sum1 = A[left=0],sum2=A[right=A.length-1],sum3=0;
		for(int i = 1;i<A.length-1;i++) {//求出初始状态三部分的和
			sum3+=A[i];
		}
		int thethree;
		if((sum1+sum2+sum3)%3 == 0) {//判断总和是不是三的倍数
			thethree = (sum1+sum2+sum3)/3;
		}else {
			return false;
		}
		while(left+1<right) {
			if(sum1!=thethree) {//左边部分与总值的三分之一不相等的时候left和sum1加一下
				sum1+=A[++left];
			}else if(sum2!=thethree) {//右边部分同理
				sum2+=A[--right];
			}else {
				return true;
			}
		}
		return false;
    }
}
```