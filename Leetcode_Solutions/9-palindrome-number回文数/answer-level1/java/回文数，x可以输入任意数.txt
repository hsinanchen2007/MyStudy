# Java实现回文数
**思路逻辑：**
![image.png](https://pic.leetcode-cn.com/c4c467aec502188c8e4b25e4b84940a6700f7d18301bf26d31041f23c2ed82ae-image.png)
**代码实现：**
`Java`
```
public class HuiWenJudge {
	/*1.判断是否是回文*/
	public boolean isPalindrome(int x) {
		if(x<0){
			System.out.print("回文不会是负数:"+x);
			return false;
		}
		String num = String.valueOf(x);
		int lengthNum = num.length();
		int i= 0;
		int j = lengthNum-1;
		if(j==0){//个位数也是回文
			System.out.println(x+" 是回文");
			return true;
		}
		while(i<j){
			//System.out.println("i:"+i+", j:"+j);
			if(num.charAt(i)==num.charAt(j)){
				int z = i + 1;
				int k = j - 1;
				//System.out.println("z:"+z+", k:"+k);
				if(z>=k){
					System.out.println(x+" 是回文");
					return true;
				}
			}else{
				System.out.println(x+" 不是回文");
				return false;
			}
			i++;
			j--;
		}
		return false;
	}
	public static void main(String[] args) {
		int x = 22;
		HuiWenJudge solution = new HuiWenJudge();
		System.out.println(solution.isPalindrome(x));
	}
}

```

