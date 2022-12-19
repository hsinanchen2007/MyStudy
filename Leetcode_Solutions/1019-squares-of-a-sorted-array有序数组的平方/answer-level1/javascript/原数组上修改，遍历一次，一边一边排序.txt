
var sortedSquares = function(A) {
for(let  right = A.length-1 ; 0<=right;right--)
			{
				if(A[0]*A[0]>=A[right]*A[right])
				{	A[0]=A[0]*A[0];
					A.splice(right+1,0,A[0])
					A.splice(0,1)
					
				}
				else
				{
					A[right]=A[right]*A[right]
					
				}
			}
     return A
};