### 解题思路
## ***数学巧妙法***
### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
      List<int[]> res = new ArrayList<>();
		int i=1;
		int mkey=i*(i+1)/2;
		while(mkey<target) {
			if((target-mkey)%(i+1)==0) {
				int x=(target-mkey)/(i+1);
				int len=i+1;
				int[] t=new int[len];
				for(int j=0;j<len;j++) {
					t[j]=x++;
				}
				res.add(t);
			}
			++i;
			mkey=i*(i+1)/2;
		}
		Collections.sort(res, new Comparator<int[]>() {

			@Override
			public int compare(int[] o1, int[] o2) {
				return o1[0]-o2[0];
			}
		});
		return res.toArray(new int[res.size()][]);
    }
}
```