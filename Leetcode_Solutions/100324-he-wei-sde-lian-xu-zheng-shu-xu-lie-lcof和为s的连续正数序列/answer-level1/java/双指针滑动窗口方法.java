### 解题思路
## 双指针向前移动

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        int low=1,high=2,sum=3;
		int upper=target%2==0?target/2:target/2+1;
		List<List<Integer>> ret=new ArrayList<>();
		List<Integer> res=new ArrayList<>();
		res.add(low);
		res.add(high);
		while(low<high&&low<upper) {
			if(sum==target) {
				ret.add(new ArrayList<>(res));
				res.remove(0);
				res.add(++high);
				sum+=high;
				sum-=low++;
			}else if(sum<target) {
				sum+=++high;
				res.add(high);
			}else {
				sum-=low++;
				res.remove(0);
			}
		}
		return list2arr(ret);
    }

    public int[][] list2arr(List<List<Integer>> ret) {
		int[][] res=new int[ret.size()][];
		for(int i=0;i<ret.size();i++) {
			int[] t=new int[ret.get(i).size()];
			for(int j=0;j<ret.get(i).size();j++) {
				t[j]=ret.get(i).get(j);
			}
			res[i]=t;
		}
		return res;
	}
}
```