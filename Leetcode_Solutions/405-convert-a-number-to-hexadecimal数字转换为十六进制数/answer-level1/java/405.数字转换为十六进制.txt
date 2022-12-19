```
class Solution {
    public String toHex(int num) {
              if(num==0)
			return "0";
		String hex="0123456789abcdef",ans="";
		while(num!=0&&ans.length()<8){
			ans=hex.charAt(num&0xf)+ans;
			num>>=4;
		}
		return ans;
    }
}
```