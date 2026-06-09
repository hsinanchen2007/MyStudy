```java
class Solution {
    
	public int[][] findContinuousSequence(int target) {
		List<int[]> sequences = new LinkedList();

		int mid = (target / 2) + 1;
		int[] sequence;
		for (int lo = 1; lo < mid; lo++) {
			int hi = lo;

			int currentSum = lo;
			while (currentSum < target) {
				currentSum += ++hi;
			}
			while (currentSum > target) {
				currentSum -= lo++;
			}
			if (currentSum == target) {
				sequence = new int[(hi - lo) + 1];
				sequences.add(sequence);
				for (int i = sequence.length - 1; hi >= lo; --i) {
					sequence[i] = hi--;
				}
			}
		}
		return sequences.toArray(new int[sequences.size()][]);
	}

}
```