```
public int findClosest(String[] words, String word1, String word2) {
    int len = words.length;
    int pre = -1, nex = -1, ans = 0x7ffffff;
    for(int i = 0;i < len;i++){
        if(word1.equals(words[i])){
            nex = i;
        }else if(word2.equals(words[i])){
            pre = i;
        }
        if(nex != -1 && pre != -1){
            ans = Math.min(ans, Math.abs(nex - pre));
        }
    }
    return ans;
}
```
