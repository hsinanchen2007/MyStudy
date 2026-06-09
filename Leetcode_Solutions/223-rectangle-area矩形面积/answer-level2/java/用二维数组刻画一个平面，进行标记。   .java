用开一个最大行-最小行，最大列-最小列大小的二维数组。
然后对二维数组进行标记，在范围内的标记为1，这样就不会担心有重复。
但是在第47个测试用例的时候，说内存超出。（应该是数组太大了，有没有大佬怎么优化比较好）

class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int maxline=Math.max(B, D);
		maxline=Math.max(F, maxline);
		maxline=Math.max(H, maxline);
		
		int minline=Math.min(B, D);
		minline=Math.min(F, minline);
		minline=Math.min(H, minline);
		
		int maxrow=Math.max(A, C);
		maxrow=Math.max(E, maxrow);
		maxrow=Math.max(G, maxrow);
		
		int minrow=Math.min(A, C);
		minrow=Math.min(E, minrow);
		minrow=Math.min(G, minrow);
		
		
		int subline=0;
		int subrow=0;
		//if(minline<0) {
			subline=-minline;
	//	}
		//if(minrow<0) {
			subrow=-minrow;
		//}
		
		int a[][]=new int [maxline-minline][maxrow-minrow];//右上平移
		
		int count=0;
		for(int i=0;i<maxline-minline;i++) {
			for(int j=0;j<maxrow-minrow;j++) {
				if(a[i][j]==0) {
					if(A+subrow<=j&&C+subrow>j&&B+subline<=i&&D+subline>i) {//这个点在矩阵1里面
						a[i][j]=1;
						count++;
					}
					else if(E+subrow<=j&&G+subrow>j&&F+subline<=i&&H+subline>i) {
						a[i][j]=1;
						count++;
					}
				}
				
			}
		}
		
		
		
        return count;
    }
}