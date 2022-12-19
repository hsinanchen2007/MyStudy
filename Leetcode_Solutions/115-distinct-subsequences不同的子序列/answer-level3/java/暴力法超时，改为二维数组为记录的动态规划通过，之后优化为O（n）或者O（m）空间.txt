优化为O（m）t.length 空间
执行结果：
通过
显示详情
执行用时 :
16 ms
, 在所有 Java 提交中击败了
58.55%
的用户
内存消耗 :
35.3 MB
, 在所有 Java 提交中击败了
90.51%
的用户
```
class Solution {
    
    public int numDistinct(String s, String t) {
        int sl = s.length();
        int tl = t.length();
        if(sl==0||tl==0)return 0;
        if(sl<tl)return 0;
        if(sl==tl)return s.equals(t)?1:0;
        int[] res = new int[tl+1];
        for(int i=0;i<sl; i++){
            int pre=0;
            
            for(int j=0;j<tl; j++){
                if(j==0)pre=1;
                int temp = res[j+1];
                if(s.charAt(i)==t.charAt(j)){
                    res[j+1]=res[j+1]+pre;
                }
                pre = temp;
             } 
        }
        return res[tl];
    }
}
```


动态规划优化为O（n)-s.length空间
执行结果：
通过
显示详情
执行用时 :
18 ms
, 在所有 Java 提交中击败了
51.52%
的用户
内存消耗 :
35.2 MB
, 在所有 Java 提交中击败了
90.51%
的用户

```
class Solution {
    
    public int numDistinct(String s, String t) {
        int sl = s.length();
        int tl = t.length();
        if(sl==0||tl==0)return 0;
        if(sl<tl)return 0;
        if(sl==tl)return s.equals(t)?1:0;
        int[] res = new int[sl+1];
        for(int i=0;i<tl; i++){
            int pre=0;
            for(int j=0;j<sl; j++){
                if(i==0)pre=1;
                int temp = res[j+1];
                if(s.charAt(j)==t.charAt(i)){
                    res[j+1]=res[j]+pre;
                }else{
                    res[j+1]=res[j];
                }
                pre = temp;
             } 
        }
        return res[sl];
    }
}
```





改为动态规划通过
执行结果：
通过
显示详情
执行用时 :
15 ms
, 在所有 Java 提交中击败了
65.11%
的用户
内存消耗 :
37.4 MB
, 在所有 Java 提交中击败了
27.74%
的用户
```
class Solution {
    
    public int numDistinct(String s, String t) {
        int sl = s.length();
        int tl = t.length();
        if(sl==0||tl==0)return 0;
        if(sl<tl)return 0;
        if(sl==tl)return s.equals(t)?1:0;
        int[][] res = new int[tl+1][sl+1];
        for(int j=0;j<sl;j++){
            res[0][j]=1;
        }
        for(int i=0;i<tl; i++){
            for(int j=0;j<sl; j++){
                if(s.charAt(j)==t.charAt(i)){
                    res[i+1][j+1]=res[i][j]+res[i+1][j];
                }else{
                    res[i+1][j+1]=res[i+1][j];
                }
             } 
        }
        return res[tl][sl];
    }
}
```



暴力法严重超时：
"adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc"
"bcddceeeebecbc"
```
class Solution {
    int  count=0;
    static Long cc=0l;
    int sl,tl;
    public int numDistinct(String s, String t) {
    	int[] pos = new int['z'+1];
    	
        sl = s.length();
         tl = t.length();
         int next[] = new int[sl];
         for(int i=sl-1;i>=0;i--) {
        	 if(pos[s.charAt(i)]==0) {
        		 pos[s.charAt(i)]=i;
        	 }else {
        		 next[i]=pos[s.charAt(i)];
        		 pos[s.charAt(i)]=i;
        	 }
         }
        
        get(s,t,0,0,next);
        return count;
    }
    private void get(String s, String t, int si, int ti,int[] next){
        cc++;
        if(ti==tl){
            count++;
            return ;
        }
        if(si==sl){
            return ;
        }
        if(sl-si<tl-ti){
            return ;
        }
        if(sl-si==tl-ti){
             // System.out.println(si+"-"+ti+s.substring(si)+"-"+t.substring(ti));
            if(s.substring(si).equals(t.substring(ti))){
                count++;
                return ;
            }else{
                return ;
            }
        }
        // System.out.println("b"+si+"-"+ti);
        if(s.charAt(si)==t.charAt(ti)){
            get(s,t,si+1,ti+1,next);
            if(next[si]!=0) {
            	get(s,t,next[si],ti,next);
            }
        }else {
        	get(s,t,si+1,ti,next);
        }
        
    }
}
```
