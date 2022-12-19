单词列表填充到前缀树，OK。
执行结果：
通过
显示详情
执行用时 :
39 ms
, 在所有 Java 提交中击败了
61.56%
的用户
内存消耗 :
58 MB
, 在所有 Java 提交中击败了
49.33%
的用户
```
class Solution {
    List<String> res = new ArrayList<>();
    public List<String> findWords(char[][] board, String[] words) {
        
        int li= words.length;
        if(li==0)return res;
        int x = board.length;
        if(x==0)return res;
        int y = board[0].length;
        Trie t2 = new Trie(' ');
        for(int i=0;i<li;i++){
            t2.addWord(words[i]);
        }
        int[][] used = new int[x][y];
        
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                used[i][j]=1;
                pro(x,y,i,j,board, t2,used);
                used[i][j]=0;
            }
        }
        //Collections.sort(res); 
        return res;
    }
   
    private void pro(int x, int y, int i,int j,char[][] b, Trie t, int[][] used){
        Trie nt = t.getCs()[b[i][j]-'a'];
        
        if(nt==null){
            return ;
        }else{
            if(nt.t){
                nt.t=false;
                res.add(nt.v);
            }
        }
        
        if(i-1>=0&&used[i-1][j]==0){
            used[i-1][j]=1;
            pro(x,y,i-1,j,b,nt,used);
            used[i-1][j]=0;
        }
        if(i+1<x&&used[i+1][j]==0){
            used[i+1][j]=1;
            pro(x,y,i+1,j,b,nt,used);
            used[i+1][j]=0;
        }
        if(j-1>=0&&used[i][j-1]==0){
            used[i][j-1]=1;
            pro(x,y,i,j-1,b,nt,used);
            used[i][j-1]=0;
        }
        if(j+1<y&&used[i][j+1]==0){
            used[i][j+1]=1;
            pro(x,y,i,j+1,b,nt,used);
            used[i][j+1]=0;
        }
    }
    
    class Trie{
        int level=1;
        boolean t;
        char c;
        String v="";
        private Trie[] cs ;
        public Trie[] getCs(){
            if(cs==null){
                cs = new Trie[26];
            }
            return cs;
        }
        public Trie(char a,String vv){
            c=a;
            v=vv;
            
        }
         public Trie(char a){
            c=a;
        }
        public void addWord(String word){
            int len= word.length();
            Trie temp  = this;
            for(int i=0;i<len; i++){
                if(temp.getCs()[word.charAt(i)-'a']==null){
                    temp.getCs()[word.charAt(i)-'a']=new Trie(word.charAt(i),temp.v+word.charAt(i));
                }
                if(i==len-1){
                    temp.getCs()[word.charAt(i)-'a'].t=true;
                }
                temp=temp.getCs()[word.charAt(i)-'a'];
            }
        }
    }
     
}
```


二维数组填充到前缀树，很快就超时了。
```
class Solution {
    int maxlen=0;
    public List<String> findWords(char[][] board, String[] words) {
        List<String> res = new ArrayList<>();
        int li= words.length;
        if(li==0)return res;
        int x = board.length;
        if(x==0)return res;
        int y = board[0].length;
        for(int i=0;i<li;i++){
            if(words[i].length()>maxlen){
                maxlen= words[i].length();
            }
        }
        int[][] used = new int[x][y];
        Trie t = new Trie(' ');
        System.out.println("maxlen"+maxlen);
        for(int i=0; i<x; i++){
            System.out.println("iii="+i);
            for(int j=0; j<y; j++){
                //reset(x,y,used);
                used[i][j]=1;
                pro(x,y,i,j,board, t,used,0);
                used[i][j]=0;
            }
        }
        System.out.println("22====maxlen"+maxlen);
        //print(t,"");
        for(int i=0;i<li;i++){
            
            if(exist(words[i],t)){
                 res.add(words[i]);
            }
        }
        return res;
    }
   
    private void pro(int x, int y, int i,int j,char[][] b, Trie t, int[][] used,int level){
        level++;
        Trie nt = t.cs[b[i][j]-'a'];
        if(nt==null){
            //System.out.println(b[i][j]);
            nt= new Trie(b[i][j]);
            t.cs[b[i][j]-'a']=nt;
        }
        if(level>=maxlen)return;
        if(i-1>=0&&used[i-1][j]==0){
            used[i-1][j]=1;
            pro(x,y,i-1,j,b,nt,used,level);
            used[i-1][j]=0;
        }
        if(i+1<x&&used[i+1][j]==0){
            used[i+1][j]=1;
            pro(x,y,i+1,j,b,nt,used,level);
            used[i+1][j]=0;
        }
        if(j-1>=0&&used[i][j-1]==0){
            used[i][j-1]=1;
            pro(x,y,i,j-1,b,nt,used,level);
            used[i][j-1]=0;
        }
        if(j+1<y&&used[i][j+1]==0){
            used[i][j+1]=1;
            pro(x,y,i,j+1,b,nt,used,level);
            used[i][j+1]=0;
        }
    }
    
    
    private void reset(int x, int y, int[][] used){
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                used[i][j]=0;
            }
        }
    }
    
    public boolean exist(String w, Trie t){
        int len = w.length();
        for(int i=0; i<len; i++){
            Trie temp = t.cs[w.charAt(i)-'a'];
            if(temp==null)return false;
            t = temp;
        }
        return true;
    }
    class Trie{
        int level=1;
        char c;
        Trie[] cs = new Trie[26];
        public Trie(char a){
            c=a;
        }
    }
    private void print(Trie t, String s){
        boolean found = false;
        
        for(int i=0; i<26; i++){
            if(t.cs[i]!=null){
                print(t.cs[i],s+t.cs[i].c);
            }
        }
        if(!found){
            System.out.println(s);
        }
    }
}
```
