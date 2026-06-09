### 解题思路
此处撰写解题思路 

### 代码
```java
class Solution {
	public List<Integer> diffWaysToCompute(String input) {
		char[] inputCharList = input.toCharArray();
		List<Integer> result = new ArrayList<Integer>();

		List<Integer> firstNumberList;
		List<Integer> secondNumberList;
		int symbolNum = 0;
		for (int i = 0; i < inputCharList.length; i++) {
			if (inputCharList[i] == '*' || inputCharList[i] == '+' || inputCharList[i] == '-') {
				firstNumberList = diffWaysToCompute(input.substring(0, i));
				secondNumberList = diffWaysToCompute(input.substring(i + 1, input.length()));

				result.addAll(getTwoNumComputeResult(firstNumberList, secondNumberList, inputCharList[i]));

				symbolNum++;
			}
		}

		if (symbolNum == 0) {
			result.add(Integer.valueOf(input));
		}
		return result;
	}

	private List<Integer> getTwoNumComputeResult(List<Integer> firstNumberList, List<Integer> secondNumberList,
			char c) {
		List<Integer> result = new ArrayList<Integer>();

		for (int i = 0; i < firstNumberList.size(); i++) {
			for (int j = 0; j < secondNumberList.size(); j++) {
				if (c == '*') {
					result.add(firstNumberList.get(i) * secondNumberList.get(j));
				}
				if (c == '+') {
					result.add(firstNumberList.get(i) + secondNumberList.get(j));
				}
				if (c == '-') {
					result.add(firstNumberList.get(i) - secondNumberList.get(j));
				}
			}
		}

		return result;
	}
}
```