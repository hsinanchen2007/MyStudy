```
class Solution {
    public int numJewelsInStones(String J, String S) {
                int a[]=new int[256];
		for(char c:J.toCharArray()){
			a[c]++;
		}

		int count=0;
		for(char c:S.toCharArray()){
			if(a[c]!=0){
				count++;
			}
		}
		return count;
    }
}
```