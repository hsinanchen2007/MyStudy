```Java
class Solution {
    public int nthUglyNumber(int n) {
    List<Integer>list=new ArrayList<>();
		list.add(1);
		int t2=0,t3=0,t5=0;
		int curNum=1;
		for(int i=1;i<n;i++){
			curNum=min(list.get(t2)*2,list.get(t3)*3,list.get(t5)*5);
			list.add(curNum);
			if(list.get(t2)*2==list.get(i)) t2++;
			if(list.get(t3)*3==list.get(i)) t3++;
			if(list.get(t5)*5==list.get(i)) t5++;
		}
		if(n==0)
			return 0;
		else return list.get(n-1);
	}
	public int min(int a,int b,int c){
		int res=a>b?b:a;
		return res>c?c:res;
	}
}
```