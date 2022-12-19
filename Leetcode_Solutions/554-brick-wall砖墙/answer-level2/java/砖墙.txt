把每层从左往右累计求和，求出每层砖所有情况的总和，重复值出现最多的就是通过缝隙最多的，拿层数减去就是最少通过砖块数

### 代码

```java
class Solution {
    public int leastBricks(List<List<Integer>> wall) {
		int[] all=new int[60000];
		int max = 0;
		for (int i = 0; i < wall.size(); i++) {
			int num = 0;//每层砖从0开始
			for (int j = 0; j < wall.get(i).size()-1; j++) {//减去最后一块砖
				num += wall.get(i).get(j);//每块砖累计求和
				all[num]+=1;//每种情况计数
			}
		}
		for (int i : all) {
			if(i==0)continue;else 	max=i>max?i:max;
		}
		return wall.size() - max;
    }
}
```