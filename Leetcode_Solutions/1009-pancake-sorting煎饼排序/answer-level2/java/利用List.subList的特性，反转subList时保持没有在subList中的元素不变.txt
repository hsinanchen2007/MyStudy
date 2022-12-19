采用官方的提示，使用了List.subList方法和Collections.reverse方法。

```
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solution {
	public List<Integer> pancakeSort(int[] A) {
		if (A == null || A.length == 1) {
			return Collections.emptyList();
		}
		List<Integer> result = new ArrayList<>();
		List<Integer> src = IntStream.of(A).boxed().collect(Collectors.toList());
		int count = A.length;
		while (count > 0) {
			int maxPos = 0;
			for (int i = 1; i < count; i++) {
				if (src.get(i) > src.get(maxPos)) {
					maxPos = i;
				}
			}
			if ((maxPos + 1) == count) {
				count--;
				continue;
			}
			result.add(maxPos + 1);
			Collections.reverse(src.subList(0, maxPos + 1));
			result.add(count);
			Collections.reverse(src.subList(0, count));
			count--;
		}
		return result;
	}
}
```
