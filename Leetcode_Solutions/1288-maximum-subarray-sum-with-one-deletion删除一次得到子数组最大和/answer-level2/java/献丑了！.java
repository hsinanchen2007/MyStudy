```java
class Solution {
    public int maximumSum(int[] arr) {
        int N = arr.length;
		int []base_maxsum = new int[N];
		base_maxsum[0] = arr[0];
		for(int i=1;i<N;i++){
			base_maxsum[i] = Math.max(arr[i],base_maxsum[i-1] + arr[i]);
		}
        //首先，这里得到最大子数组的前缀和？这样称呼可能有问题，举个例子就好了；
        //例如数组[1,2,3,4] ====> [1,3,6,10];
        //[1,-2,3,4] ====>[1,-2,3,6];


		int []maxsums = new int[N];
		maxsums[0] = arr[0];
		for(int i=1;i<N;i++){
			int prev_sum = maxsums[i-1];
			int prev_basesum = base_maxsum[i-1];
			int num = arr[i];
			if(prev_sum >= 0){  //现在开始往后加数据
				if(num > 0) //如果该数据大于0,不用删除直接加进去
					maxsums[i] = prev_sum + num;
				else //否则,就要考虑要不要删除这个数，毕竟只有一次机会删除，一定要删一个最优的
                        //，但不一定是最小的，那么刚刚求的前缀和就用到了，看看是前缀和大，还是删了之后大
					maxsums[i] = Math.max(prev_basesum,prev_sum + num);
			}
			else{
				maxsums[i] = num;
			}
		}
		Arrays.sort(maxsums);
		return maxsums[N-1];
    }
}
```
