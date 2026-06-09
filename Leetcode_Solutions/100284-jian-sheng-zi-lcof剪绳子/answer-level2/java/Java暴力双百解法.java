不难发现，将长度为n的绳子剪成m段。满足每段都是n/m时，乘积最大。
但n/m可能不是整数。

```dart
int num=n/m;
int left=n%m;//剩下的长度为left（left<m)
//把剩下的left长度分给，left段，即有left段长度为num+1,有m-left段长度为num
```
然后遍历段数从2到n找到最大值即可。以下为Java代码

```reasonml
public static int cuttingRope(int n) {
	int result=0;
	for(int i=2;i<=n;i++){//可以分成2~n段,遍历所有可能
		result=Math.max(my_length(n,i), result);
	}
        return result;
    }

public static int my_length(int n,int m){//长度为n的绳子，剪成n段的最大乘积
        int num=n/m;//平均数为num
	int left = n%m;//有left个num+1,所以有m-left个num
	int result = (int) (Math.pow(num+1, left)*Math.pow(num, m-left));
	return result;	
	}
```
