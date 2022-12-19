执行用时 :16 ms, 在所有 java 提交中击败了93.35%的用户
内存消耗 :51.6 MB, 在所有 java 提交中击败了100.00%的用户

把所有的product加入字典树中，节点存放前三个product. 每次加入判断并从新排序。

```
class Solution {
    class TrieNode{
        int size;
        String[] strarr;
        int chflag;
        TrieNode[] child;
        TrieNode(){
            size=0;
            strarr=new String[3];
            chflag=0;
            child=new TrieNode[26];
        }
    }
    TrieNode root;

    void addTrieNode(String s){
        TrieNode ref=root;
        for(int i=0;i<s.length();i++){
            int idx=s.charAt(i)-'a';
            if((ref.chflag & (1<<idx))==0){
                ref.chflag |= 1<<idx;
                ref.child[idx]=new TrieNode();
            }
            ref=ref.child[idx];
            if(ref.size<3){
                ref.strarr[ref.size++]=s;
                int k=ref.size-1;
                while(k>0 && ref.strarr[k].compareTo(ref.strarr[k-1])<0){
                        String tmp=ref.strarr[k];
                        ref.strarr[k]=ref.strarr[k-1];
                        ref.strarr[k-1]=tmp;
                        k--;
                }
            }
            else if(s.compareTo(ref.strarr[2])<0){
                ref.strarr[2]=s;
                int k=2;
                while(k>0 && ref.strarr[k].compareTo(ref.strarr[k-1])<0){
                    String tmp=ref.strarr[k];
                    ref.strarr[k]=ref.strarr[k-1];
                    ref.strarr[k-1]=tmp;
                    k--;
                }
            }
        }
    }
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        List<List<String>> listlist=new ArrayList<>();
        root=new TrieNode();
        int i;
        for(i=0;i<products.length;i++){
            addTrieNode(products[i]);
        }
        TrieNode ref=root;
        int slen=searchWord.length();

        for(i=0;i<slen;i++){
            int idx=searchWord.charAt(i)-'a';
            if((ref.chflag & (1<<idx))==0){
                break;
            }
            ref=ref.child[idx];
            List<String> list=new ArrayList<>();
            if(ref.size>0){
                for(int j=0;j<ref.size;j++){
                    list.add(ref.strarr[j]);
                }
            }
            listlist.add(list);
        }
        for(;i<slen;i++){
            List<String> list=new ArrayList<>();
            listlist.add(list);
        }
        return listlist;
    }
}
```
