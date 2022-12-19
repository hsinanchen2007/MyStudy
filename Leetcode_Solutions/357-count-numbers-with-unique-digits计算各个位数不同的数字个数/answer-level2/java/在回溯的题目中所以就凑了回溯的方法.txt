### 解题思路
用递归加回溯的方法
### 代码

```java
class Solution {
    static int total;
	static int number;
	static int N;
	static boolean[] visited;
	static Set<String> results;
    
    public static int countNumbersWithUniqueDigits(int n) {
    	visited=new boolean[10];
    	results=new HashSet<String>();
    	N=n;
        total=0;
        number=Double.valueOf(Math.pow(10, n)).intValue();
        	dfs(0,0,0);
        return results.size();
    }
	private static void dfs(int step,int num,int key) {
		if(step>=0&&step<=N){
			Integer temp=num;
			results.add(temp.toString());
		}
		if(num>=number){
			return;
		}
		if(step==0){
//第一个数可以取的值
			for(int i=1;i<=9;i++){
				num=i;
				step++;
				visited[i]=true;
				dfs(step,num,i);
				visited[i]=false;
				num=0;
				step--;
			}
		}
		if(step>0){
//后面的数可以取的值用访问数组的方式判断每个数字不能重复的加入每次递归完成后进行回溯
			for(int i=0;i<=9;i++){
				if(!visited[i]){
					step++;
					visited[i]=true;
					num=num*10+i;
					dfs(step,num,i);
					visited[i]=false;
					num=(num-i)/10;
					step--;
				}else{
					continue;
				}
			}
		}
	}
}
```