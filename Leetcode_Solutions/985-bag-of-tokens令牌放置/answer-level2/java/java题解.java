执行用时 :5 ms, 在所有 Java 提交中击败了76.92%的用户
主要思路:先对数组进行排序，当我的能量大于令牌中最小值时，令牌向上并且指针向右移动，当能量小于当前最小值时，判断当前能力加上最大能量值能否大于当前能量最小值，并且移动相应指针。
以下为代码：
```
public int bagOfTokensScore(int[] tokens, int P) {
		int length=tokens.length;
		if(length==0)return 0;
		if(length==1)return P>tokens[0]?1:0;
		int score=0;
		int left=0,right=length-1;
		Arrays.sort(tokens);
		while (left<=right){
			if (P>=tokens[left]){//当前能量是否大于当前令牌最小值
				P-=tokens[left];
				score++;
				left++;
			}else {
				if (P+tokens[right]>tokens[left] && score>0 ){ //当前能量+当前令牌最大值是否大于当前令牌最小值
					P=P+tokens[right]-tokens[left];
					right--;
					left++;
				}else break;
			}
		}
		return score;
	}
```
