```Java
/**
 * 循环解法，每次放置最小的丑数
 */
class Solution{
	public boolean isUgly(int num){
		if(num==Integer.MAX_VALUE)
			return false;
		List<Integer>list=new ArrayList<>();
		list.add(1);
		int t2=0,t3=0,t5=0;
		int curNum=1,i=0;
		while(curNum<num){
			curNum=min(list.get(t2)*2,list.get(t3)*3,list.get(t5)*5);
			list.add(curNum); i++;
			if(list.get(t2)*2==list.get(i)) t2++;
			if(list.get(t3)*3==list.get(i)) t3++;
			if(list.get(t5)*5==list.get(i)) t5++;
		}
		if(curNum==num)
			return true;
		else return false;
	}
	public int min(int a,int b,int c){
		int res=a>b?b:a;
		return res>c?c:res;
	}
}

/**
 * 递归解法
 */
class Solution{
	public boolean isUgly(int num){
		if(num==0) return false;
		if(num==1) return true;
		if(num%2==0) return isUgly(num/2);
		if(num%3==0) return isUgly(num/3);
		if(num%5==0) return isUgly(num/5);
        return false;
	}
}
```