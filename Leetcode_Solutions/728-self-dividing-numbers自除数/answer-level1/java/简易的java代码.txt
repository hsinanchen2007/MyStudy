### 代码

```java
class Solution {
    public List<Integer> selfDividingNumbers(int left,int right){
		List<Integer> resList = new ArrayList<>();
		for(int i=left;i<=right;i++){
			if(isSelfDividingNumbers(i)){
				resList.add(i);
			}
		}
		return resList;
	}
	
	public boolean isSelfDividingNumbers(int num){
		int myNum = num;
		
		// int表示的数最大数量级为1000000000
		int weight = 0;
		for(int i=1000000000;i>=1;i=i/10){
			if(num/i!=0){
				weight = i;
				break;
			}
		}
		// 拆解出num的各位数字
		List<Integer> digits = new ArrayList<>();
		while(weight>=1){
			int curr = num/weight;
			// System.out.println(curr);
			digits.add(curr);
			num = num - curr*weight;
			weight = weight / 10;
		}
		// 检查各位数字是否都能整除num
		for(int i=0;i<digits.size();i++){
			if(digits.get(i) == 0 ||myNum % digits.get(i) != 0){
				// 前一个条件是因为自除数不允许包括0
				return false;
			}
		}
		return true;
	}
}
```