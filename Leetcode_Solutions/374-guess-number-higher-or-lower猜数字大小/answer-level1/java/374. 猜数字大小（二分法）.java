这题中出现的
> -1 : 我的数字比较小
 1 : 我的数字比较大
 0 : 恭喜！你猜对了！

-1指的是真实的结果比较小（即你猜的结果大），而不是你猜的小。

```Java
public class Solution extends GuessGame{
	public int guessNumber(int n){
		int low=1,high=n;
		while(low<=high){
			int mid=low+(high-low)/2;
			int res=guess(mid);
			if(res!=0){
				if(res==-1){
					high=mid-1;
				}else {
					low=mid+1;
				}
			}else{
				return mid;
			}
		}
		return 0;
	}
}
```