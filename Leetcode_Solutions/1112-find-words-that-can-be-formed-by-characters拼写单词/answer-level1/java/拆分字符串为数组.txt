执行用时 :12 ms, 在所有 Java 提交中击败了91.61%的用户
内存消耗 :50.2 MB, 在所有 Java 提交中击败了100.00%的用户

```
class Solution {
    public int countCharacters(String[] words, String chars) {
        int lengths = 0;
        int cnt = 0;
        char[] alphbet = chars.toCharArray();
        int [] count = new int[100];
        boolean[] isClear = new boolean[1001];
        for(char charItem:alphbet){
          count[charItem-97]++;
        }
      for(String item:words){
        int[] countCopy = Arrays.copyOf(count,count.length);
        char[] tmp = item.toCharArray();
        for(char tmpItem:tmp){
          if(countCopy[tmpItem-97]==0){
            isClear[cnt]=false;
            break;
          }else{
            countCopy[tmpItem-97]--;
            isClear[cnt]=true;
          }
        }
        cnt++;
      }
      for(int i=0;i<isClear.length;i++){
        if(isClear[i]){
          lengths+=words[i].length();
        }
      }
      return lengths;
    }
}
```
