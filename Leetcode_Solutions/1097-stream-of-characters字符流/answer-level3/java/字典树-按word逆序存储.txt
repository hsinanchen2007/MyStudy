执行用时 :119 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :83.5 MB, 在所有 java 提交中击败了100.00%的用户

注意记录最长word长度，搜索时超过最长就返回。
```
class StreamChecker {
    class TrieNode{
        int widx;
        int chflag;
        TrieNode[] child;
        TrieNode(){
            widx=-1;
            chflag=0;
            child=new TrieNode[26];
        }
    }
    int maxlen;
    char[] buf;
    int curidx;
    TrieNode root;
    void addTrieNode(String word,int _widx){
        TrieNode ref=root;
        int len=word.length();
        if(len>maxlen){
            maxlen=len;
        }
        for(int i=len;i>0;i--){
            int idx=word.charAt(i-1)-'a';
            if((ref.chflag & (1<<idx))==0){
                ref.chflag |= 1<<idx;
                ref.child[idx]=new TrieNode();
            }
            ref=ref.child[idx];
        }
        ref.widx=_widx;
    }

    boolean search(){
        TrieNode ref=root;
        int backcnt=0;
        int i=curidx;
        while(backcnt<maxlen & i>0){
            int idx=buf[i-1]-'a';
            if((ref.chflag & (1<<idx))==0){
                return false;
            }
            backcnt++;
            i--;
            ref=ref.child[idx];
            if(ref.widx>=0)return true;
        }
        return false;
    }
    public StreamChecker(String[] words) {
        maxlen=0;
        buf=new char[40000];
        curidx=0;
        root=new TrieNode();
        int size=words.length;
        for(int i=0;i<size;i++){
            addTrieNode(words[i],i);
        }
    }

    public boolean query(char letter) {
        buf[curidx++]=letter;
        return search();
    }
}
```
