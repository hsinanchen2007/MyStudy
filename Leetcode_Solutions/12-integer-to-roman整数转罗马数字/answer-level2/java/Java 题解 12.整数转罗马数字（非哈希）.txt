## 执行
```
执行用时 : 21 ms, 在Integer to Roman的Java提交中击败了92.57% 的用户
内存消耗 : 35.8 MB, 在Integer to Roman的Java提交中击败了100.00% 的用户
```

## 思路
  用list保存罗马数字，筛选出特殊情况，分别有0,4,5,9及其他，以5为分界线，进行%5操作来判断数字是否是4,9两种特殊情况，原数字%10判断数字是否>4来判断是否需要补上5这个罗马数字。

## 代码
```
class Solution {
    public String intToRoman(int num) {
		List<String> list = new ArrayList<>();
		list.add("I");//1
		list.add("V");//5
		list.add("X");//10
		list.add("L");//50
		list.add("C");//100
		list.add("D");//500
		list.add("M");//1000
		int pos = 0;
		StringBuilder sb = new StringBuilder();
		while (num != 0) {
			if (num % 5 == 4) {
				sb.insert(0, list.get(pos + num % 10 / 5 + 1));
				sb.insert(0, list.get(pos));
			} else {
				for (int i = num % 5; i > 0; i--) {
					sb.insert(0, list.get(pos));
				}
				if (num % 10 > 4) {
					sb.insert(0, list.get(pos + 1));
				}
			}
			num /= 10;
			pos += 2;
		}
		return sb.toString();
    }
}
```