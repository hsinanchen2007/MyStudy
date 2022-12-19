### 解题思路
Uman

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
		List<Integer> s=new ArrayList<Integer>();
		List<List<Integer>> re=new ArrayList<>();
		int i=1;
		while(i<=(target+1)/2){
			int sum=i;
			int temp=i;
			while((target-sum)>=(temp+1)){
				s.add(temp);
				temp=temp+1;
				sum=sum+temp;
				
			}
			if(sum==target){
				s.add(temp);
				re.add(new ArrayList(s));
			}
			s.clear();
			i++;
		}
		
		int[][] result=new int[re.size()][];
		for(int k=0;k<re.size();k++){
			List<Integer> temp2=re.get(k);
            result[k]=new int[temp2.size()];
			for(int j=0;j<temp2.size();j++){
				result[k][j]=temp2.get(j);
			}
		}
		
		
		return result;
    }
}
```