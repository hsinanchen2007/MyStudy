### 解题思路
看了一圈题解，借鉴了大佬们的思路，为了方便像我这样的菜鸡们理解，决定写一篇题解（大佬勿喷）

这个算法是这样的：先找出2个连续的和为target的数，再找出连续的3个、4个......怎么找呢？其实是算出来的。这里我每次算出序列中最小的那个数。假设有2个数的和等于target,设最小的那个数的值为n，显然n+(n+1)=target,则n=(target-1)/2;如果没有2个数的和为target，那么假设有3个，则有n+(n+1)+(n+2)=target,n=(target-1-2)/3;以此类推,如果我们用i来表示序列长度(代码中我设置初值为1，方便对target做减法)，那么长度为i的序列中最小的那个数n(target-(1+2+3+...+i-1))/i.

还有就是，显然，在和相等的情况下，序列越长它的头部的那个数就越小。由于我们从序列最短的情况开始求，因此最后我们只要把ArrayList倒序复制（其实只是复制了地址）到二维数组中即可。
### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        ArrayList<int[]> ans=new ArrayList();
        int i=1;
        while(target>0) {
           /*对target做减法，注意此时i不是数列长度*/
        	target-=i;
           /*此时i才代表数列长度*/                   
        	i++;
        	if(target>0&&target%i==0) {
                /*申请长度为i的数组用于储存*/
        		int[] temp=new int[i];
                /*将每个数放到数组里*/
        		for(int star=target/i,q=0;star<target/i+i;star++,q++) {
        			temp[q]=star;
        		}
        		ans.add(temp);
        	}
        }
        int size=ans.size();
        int[][] arr=new int[size][];
        /*倒序复制*/
        for(int j=size-1,k=0;j>=0;j--,k++) {
        	arr[k]=ans.get(j);
        }
        return arr;
    }
}
```