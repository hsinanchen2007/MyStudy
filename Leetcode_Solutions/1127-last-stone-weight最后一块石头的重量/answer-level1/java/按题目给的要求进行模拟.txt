### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lastStoneWeight(int[] stones) {
        int index=stones.length-1;
		while(index!=0) {
			Arrays.sort(stones);
//			for(int i=0;i<index;i++) {
//				System.out.print(stones[i]+" ");
//			}
//			System.out.println();
			if(index-1>=0) {
				int y=stones[index];
				int x=stones[index-1];
				if(x==y) {
					index-=2;
					if(index<0) {
						return 0;
					}
				}
				else {
					stones[index-1]=y-x;
					index--;
				}
			}
		}
		return stones[index];
    }
}
```