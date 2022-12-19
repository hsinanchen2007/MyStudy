![image.png](https://pic.leetcode-cn.com/dc91e13829e3fdb776b2ab241fe4faa3544ada15afab457308a00c7bcdabc6a7-image.png)

Trie树上跑dfs就可以了，跑赢了50%，听说还可以剪枝优化，不过我不会...
具体看代码吧...
```
class Solution {

    static class Trie{
        Trie next[] = new Trie[26];
        boolean end;
        boolean isCount;        //当前节点是否已被计入答案，用于去重
    }

    Trie root = new Trie();
    List<String> list = new ArrayList<String>();
    char board[][];
    int m,n;

    public List<String> findWords(char[][] board, String[] words) {
        m = board.length;
        n = board[0].length;
        this.board = board;
        for(int i=0;i<words.length;i++){
            insert(words[i]);
        }
        boolean flag[][] = new boolean[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                search(i,j,"",flag,root);
            }
        }
        return list;
    }

    private void insert(String s){      //Trie树 insert
        Trie p = root;
        for(int i=0;i<s.length();i++){
            int k = s.charAt(i) - 'a';
            if(p.next[k]==null) p.next[k] = new Trie();
            p = p.next[k];
        }
        p.end = true;
    }

    private void search(int i,int j,String str,boolean flag[][],Trie root){     //递归search
        Trie p = root;
        int k = board[i][j] - 'a';
        flag[i][j] = true;
        str += board[i][j];
        if(p.next[k]!=null){
            if(p.next[k].end && !p.next[k].isCount) {
                list.add(new String(str));
                p.next[k].isCount = true;
            }
            if(i+1<m && !flag[i+1][j]) search(i+1,j,str,flag,p.next[k]);
            if(i-1>=0 && !flag[i-1][j]) search(i-1,j,str,flag,p.next[k]);
            if(j+1<n && !flag[i][j+1]) search(i,j+1,str,flag,p.next[k]);
            if(j-1>=0 && !flag[i][j-1]) search(i,j-1,str,flag,p.next[k]);
        }
        str = str.substring(0,str.length()-1);
        flag[i][j] = false;
    } 
}
```
