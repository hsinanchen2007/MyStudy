### 解题思路
就是定义l，r.l为左端，r为右端。(l+r)(r-l+1)=2*target。
化简后得到r*r+r=2*target-l+l*l。
然后就是暴力。可能验证即is()那边要验证。下次一定。
就是那边long写的特别繁琐，如果有简便写法，求教.
### 代码

```java
class Solution {
     int is(long n)
	{
	   long s= (long) Math.sqrt(n);
       long s1=s*s+s;
		if(s1==n) return (int)s;
		return -1;
	}
   public   int[][] findContinuousSequence(int target) {

   List<int []> al=new ArrayList();
       for(int i=1;i<=target/2;i++)
       {
       	 long sum1=2*(long)target-(long)i+(long)i*(long)i;
       //	System.out.println(i+" "+sum1+" "+is(sum1));
       	if(is(sum1)==-1) continue;
       	else 
       	{
       		int r=is(sum1);
       		if(r<=i) break;
       		else 
       		{
       			int []a=new int[r-i+1];
       			for(int j=0;j<a.length;j++)
       				a[j]+=j+i;
                   al.add(a);
       		}
       	}
       }
       return al.toArray(new int[al.size()][]);
   }
}
```