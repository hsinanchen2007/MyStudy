执行结果：
通过
显示详情
执行用时 :
299 ms
, 在所有 Java 提交中击败了
18.62%
的用户
内存消耗 :
72.2 MB
, 在所有 Java 提交中击败了
9.83%
的用户
```
class Solution {
    public int minCut(String s) {
        int len = s.length();
        Map<Integer,Set<Integer>> map = new HashMap<>(len);
        if(len<2)return 0;
        for(int i=0; i<len; i++){
            Set<Integer> list = new HashSet<>();
            list.add(i+1);
            map.put(i,list);
        }
        for(int i=1; i<len; i++){
            for(int j=i-1;j>=0;j--){
                if(i+1+i-j>len)break;
                if(isP(s,j,i,i+1,i+1+i-j)) {
                    map.get(j).add(i+1+i-j);
                }else{
                    break;
                }
            }

            if(s.charAt(i)==s.charAt(i-1)){
                map.get(i-1).add(i+1);
                for(int j=i-2;j>=0;j--){
                    if(i+i-j>len)break;
                    if(isP(s,j,i-1,i+1,i+i-j)) {
                        map.get(j).add(i+i-j);
                    }else{
                        break;
                    }
                }
            }
        }

        Set<Integer> ll = map.get(0);
        int count=0;
        boolean found=false;
        while(!ll.isEmpty()){

            Set<Integer> nll = new HashSet<>();
            for(Integer i:ll){
                if(i==len)return count;
                Set<Integer> ml = map.get(i);
                for(Integer x:ml){
                    if(x==len) {
                        found=true;
                        break;
                    }
                    nll.add(x);
                }
            }
            if(found)return ++count;
            ll=nll;
            count++;
        }
        return count;
    }
	 private boolean isP(String s, int s1, int e1, int s2, int e2) {
		 int x=0;
		 int len=e1-s1;
		 while(x<len) {
			 if(s.charAt(s1+x)!=s.charAt(e2-1-x)) {
				 return false;
			 }
		     x++;
		 }
		 return true;
	 }
}
```
