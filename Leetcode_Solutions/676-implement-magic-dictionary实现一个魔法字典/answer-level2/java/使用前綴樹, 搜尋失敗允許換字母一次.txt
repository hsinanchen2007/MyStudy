### 解题思路

建立前綴樹

搜尋時, 搜尋成功的條件為:(1)需為完整單字(不可為單字內的部份),(2)換字母一次.


### 代码

```java
class MagicDictionary {

    /** Initialize your data structure here. */
    class Nd {//前綴樹的節點
        boolean isWd;//註記該節點為一個字的結束(該節點為最後一個字母)
        Nd[] children=new Nd[26];//下一個字母的節點(0~25, 共 26 個字母)
    }
    Nd root;//前綴樹的根節點
    public MagicDictionary() {
        root=new Nd();
    }
    
    void insert(char[] chs){//依輸入的字母數組建立前綴樹上的節點
        Nd cNd=root;
        int cIx=0;
        while(cIx<chs.length){//
            char ch=chs[cIx++];//取出下一個未處理字母
            if(cNd.children[ch-'a']==null) cNd.children[ch-'a']=new Nd();//若該字母節點不存在,則建立
            cNd=cNd.children[ch-'a'];//跳到下一個字母節點
        }
        cNd.isWd=true;//對最後一個字母節點註記為單字的最後一個字母
    }
    
    /* 前綴樹節點搜尋, chs 為查詢字, cIx 為查詢索引, magicCnt 為換字母次數 */
    boolean magicSearch(Nd cNd, char[] chs, int cIx, int magicCnt){
        if(cIx==chs.length){//若查詢字內所有字母皆已訪問
            return cNd.isWd && magicCnt==0;//若最後一個前綴樹節點有註記為單字,且不需再換字母,回傳真
        }
        char ch=chs[cIx];//取待確認字母
        boolean succ=false;
        if(cNd.children[ch-'a']!=null){//若該字母存在,則遞迴訪問,若成功則直接回傳
            succ=magicSearch(cNd.children[ch-'a'], chs, cIx+1, magicCnt);
            if(succ) return succ;
        }
        if(magicCnt>0){//若失敗,但仍可換字母
            magicCnt--;//使用一次換字母機會
            for(int ix=0;ix<cNd.children.length;ix++){//訪問所有的下一個字母
                if(cNd.children[ix]==null) continue;//若不存在則略過
                if(ix==ch-'a') continue;//若和原字相同,也略過(必須滿足換字母操作)
                succ=magicSearch(cNd.children[ix],chs,cIx+1,magicCnt);//若成功則直接回傳
                if(succ) return succ;
            }
        }
        return false;
    }
    
    /** Build a dictionary through a list of words */
    public void buildDict(String[] dict) {
        for(String wd:dict){
            insert(wd.toCharArray());//對每個單字建立前綴樹節點
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    public boolean search(String word) {
        char[] chs=word.toCharArray();
        return magicSearch(root,chs,0,1);//執行前綴樹搜尋,由 0 開始, 需換字母一次
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * boolean param_2 = obj.search(word);
 */
```