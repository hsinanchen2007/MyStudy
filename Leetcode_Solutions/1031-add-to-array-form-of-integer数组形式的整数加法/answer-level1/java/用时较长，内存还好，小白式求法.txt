```
class Solution {
   	public List<Integer> addToArrayForm(int[] A, int K) {
		List<Integer> list = new ArrayList<>();
		String K_str = K + "";//将K转换为字符串处理
		int carray = 0;//后面就是常规的位对位加法运算
		for (int i = K_str.length() - 1, j = A.length - 1; i >= 0 || j >= 0; i--, j--) {
			int sum = carray;
			sum += i >= 0 ? K_str.charAt(i) - '0' : 0;
			sum += j >= 0 ? A[j] : 0;
			list.add(sum % 10);
			carray = sum / 10;
		}
		if (carray > 0) {
			list.add(1);
		}
		Collections.reverse(list);//反转
		return list;
	}
}
```
