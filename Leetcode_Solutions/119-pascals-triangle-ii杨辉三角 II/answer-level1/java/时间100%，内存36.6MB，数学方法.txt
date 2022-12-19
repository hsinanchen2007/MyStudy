直接用蛮力算，第n行第m个数就是C(m,n),根据公式C(n,m) = n!/((n-m)! * m!)就可以算出来
这里面大部分数都会约掉但是这样会超int，所以要学会化简（所以我用了long）。
就拿33行来说，**第0个数是1，第1个数是33/1，第2个数是33/1 X 32/2，第3个数是33/1 X 32/2 X 31/3。。。。**
以此类推，到第17个数就好了，第18个数前面已经算过了，直接for循环倒序添加就可以了
```
class Solution {
    static Integer fun(Integer aa,int n,int m) 
		{
		 long  sum=aa; 
			 sum=sum*n/m;
		    return (int) sum;
		}
    public List<Integer> getRow(int rowIndex) {
        int j=rowIndex/2;
        List<Integer> list = new ArrayList<>();
		list.add(1);
		for(int i=1;i<=rowIndex;i++,rowIndex--){
			list.add(fun(list.get(i-1),rowIndex, i));
		}
        for(int i=0;i<j;i++){
            list.add(list.get(j-i-1));
        }
        return list;
    }
}
```
还是要学好数学。。。。。。。
我感觉我内存用得够少了，为什么才超过一点点人。。。。。。
