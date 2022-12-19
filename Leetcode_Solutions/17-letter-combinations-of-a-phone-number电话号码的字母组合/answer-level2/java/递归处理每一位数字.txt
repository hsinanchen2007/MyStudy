执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.88%
的用户
内存消耗 :
34.9 MB
, 在所有 Java 提交中击败了
91.76%
的用户
```
class Solution {
    char emp = ' ';
    public List<String> letterCombinations(String digits) {
		
		List<String> res = new ArrayList<String>();
		if(digits==null||digits.length()==0)return res;
		char[] chars = digits.toCharArray();
        int[] str = new int[chars.length];
        for(int i=0; i<str.length; i++){
            //System.out.println(Integer.valueOf(""+chars[i]));
            str[i]=Integer.valueOf(""+chars[i]);
        }
        
		int[][] map = new int[10][4];
		
		map[2][0] = (int) 'a';
		map[2][1] = (int) 'b';
		map[2][2] = (int) 'c';
		map[2][3] = (int) emp;
		map[3] = new int[] { 'd', 'e', 'f',emp };
		map[4] = new int[] { 'g', 'h', 'i',emp };
		map[5] = new int[] { 'j', 'k', 'l' ,emp};
		map[6] = new int[] { 'm', 'n', 'o',emp };
		map[7] = new int[] { 'p', 'q', 'r','s' };
		map[8] = new int[] { 't', 'u', 'v' ,emp};
		map[9] = new int[] { 'w', 'x', 'y','z' };
		
		
		
		return get(str,map,str.length-1);
    }
	private List<String> get(int[] str, int[][]map,  int i){
		List<String> res = new ArrayList<String>();
		if(i==0){
			
			for(int k=0; k<4; k++){
				if(map[(int)str[i]][k]!=(int)emp){
					res.add(""+(char)map[(int)str[i]][k]);
				}
			}
			return res;
		}else{
			List<String> sub = get(str,map,i-1);
			for(int k=0; k<4; k++){
				int ik = (char)map[(int)str[i]][k];
				if(ik!=(int)emp){
					for(int j=0; j<sub.size(); j++){
						res.add(sub.get(j)+(char)ik);
					}
					 
				}
			}
			return res;
		}
	}
}
```