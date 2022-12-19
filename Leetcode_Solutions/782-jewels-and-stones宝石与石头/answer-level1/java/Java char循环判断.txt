把字符串转换为char数组，然后遍历char数组判断是否为宝石
```
class Solution {
    public int numJewelsInStones(String J, String S) {
        int count=0;
        char [] ch1=J.toCharArray();
        char [] ch2=S.toCharArray();
        for(char ch3 :ch1){
            for(char ch4 :ch2){
                if(ch3==ch4){
                  count++;  
                }
            }
        }
        return count;
    }
}
```
