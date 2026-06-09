
执行用时 :214 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :74.1 MB, 在所有 java 提交中击败了96.67%的用户

####
```
class WordFilter {
    int size;
    class LinkNode{
        int idx;
        LinkNode next;
        LinkNode(int _idx){
            idx=_idx;
            next=null;
        }
    }
    class TrieNode{
        int chflag;
        TrieNode[] child;
        LinkNode head;
        TrieNode(){
            chflag=0;
            head=null;
            child=new TrieNode[26];
        }
    }
    TrieNode preroot;
    TrieNode sufroot;

    void addTrieNode(String word,int idx){
        int len=word.length();
        TrieNode pref=preroot;
        TrieNode sref=sufroot;
        for(int i=0;i<len;i++){
            int pidx=word.charAt(i)-'a';
            if((pref.chflag & (1<<pidx))==0){
                pref.chflag |= 1<<pidx;
                pref.child[pidx]=new TrieNode();
            }
            pref=pref.child[pidx];
            LinkNode plnode=new LinkNode(idx);
            plnode.next=pref.head;
            pref.head=plnode;

            int sidx=word.charAt(len-i-1)-'a';
            if((sref.chflag & (1<<sidx))==0){
                sref.chflag |= 1<<sidx;
                sref.child[sidx]=new TrieNode();
            }
            sref=sref.child[sidx];
            LinkNode slnode=new LinkNode(idx);
            slnode.next=sref.head;
            sref.head=slnode;
        }
    }

    TrieNode searchPreTrie(String word){
        int len=word.length();
        TrieNode pref=preroot;
        for(int i=0;i<len;i++){
            int pidx=word.charAt(i)-'a';
            if((pref.chflag & (1<<pidx))==0){
                return null;
            }
            pref=pref.child[pidx];
        }
        return pref;
    }

    TrieNode searchSufTrie(String word){
        int len=word.length();
        TrieNode sref=sufroot;
        for(int i=0;i<len;i++){
            int sidx=word.charAt(len-i-1)-'a';
            if((sref.chflag & (1<<sidx))==0){
                return null;
            }
            sref=sref.child[sidx];
        }
        return sref;
    }

    public WordFilter(String[] words) {
        preroot=new TrieNode();
        sufroot=new TrieNode();
        size=words.length;
        for(int i=0;i<size;i++){
            addTrieNode(words[i],i);
        }
    }

    public int f(String prefix, String suffix) {
        int plen=prefix.length();
        int slen=suffix.length();
        int res=-1;
        if(plen==0 && slen==0){
            res=size-1;
        }
        else if(slen==0){
            TrieNode pref=searchPreTrie(prefix);
            if(pref!=null && pref.head!=null){
                res=pref.head.idx;
            }
        }
        else if(plen==0){
            TrieNode sref=searchSufTrie(suffix);
            if(sref!=null && sref.head!=null){
                res=sref.head.idx;
            }
        }
        else{
            TrieNode pref=searchPreTrie(prefix);
            TrieNode sref=searchSufTrie(suffix);
            if(pref!=null && sref!=null && pref.head!=null && sref.head!=null){
                LinkNode plref=pref.head;
                LinkNode slref=sref.head;
                while(plref!=null && slref!=null){
                    if(plref.idx==slref.idx){
                        res=plref.idx;
                        break;
                    }
                    else if(plref.idx>slref.idx){
                        plref=plref.next;
                    }
                    else {
                        slref = slref.next;
                    }
                }

            }
        }
        return res;
    }
}
```


