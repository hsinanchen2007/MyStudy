### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int [] [] number=new int[n][n];
	     	boolean[][] getflag=new boolean[n][n];
            boolean add=false;
	     	int flag=0,current=1;
	     	int left=0,right=0;
			//current大于n*n说明已经填充完成
	     	while (current<=n*n) {
	     		
				switch (flag) {
				case 0:
					//当前位置是否已填充过
					if (getflag[left][right]) {
						left++;
						right--;
						flag++;
					}
					else {
						number[left][right]=current;
						getflag[left][right]=true;
                        add=true;
						right++;
						//当到达边界时，改变填充方向
						if (right==n) {
							flag++;
							left++;
							right--;
						}
					}
					break;
				case 1:
					if (getflag[left][right]) {
						left--;
						right--;
						flag++;
					}
					else {
					number[left][right]=current;
					getflag[left][right]=true;
                     add=true;
					left++;
					if (left==n) {
						flag++;
						left--;
						right--;
					}
					}
					break;
				case 2:
					if (getflag[left][right]) {
						left--;
						right++;
						flag++;
					}
					else {
					number[left][right]=current;
					getflag[left][right]=true;
                     add=true;
					right--;
					if (right==-1) {
						flag++;
						left--;
						right++;
					}}
					break;
				case 3:
					if (getflag[left][right]) {
						left++;
						right++;
						flag=0;
					}
					else {
					number[left][right]=current;
					getflag[left][right]=true;
                     add=true;
					left--;
					if (left==-1) {
						left++;
						right++;
						flag=0;
					}}
					break;
				default:
					break;
				}
				//确定是否有实数值添加进入数组，若仅仅因为位置已经填充改变了方向，则不应增加数值current
                if(add){
				current++;
                }
                add=false;
			}
	     	return number;
    }
}
/*
```实质就是进行遍历，当到达各行各列的尽头时，改变填充的方向，填充按照 右 下  左 上 顺序进行填充
	同时需要注意当到达的数组位置已经填充完成时，同样需要改变方向，故采用一个布尔数组存储已经填充的位置、
当填充的数值达到n*n+1时说明此时已经填充完成。
*?