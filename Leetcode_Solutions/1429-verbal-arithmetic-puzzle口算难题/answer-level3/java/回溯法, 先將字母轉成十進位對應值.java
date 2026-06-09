### 解题思路
參考 https://leetcode-cn.com/u/tom-chan/ 在比賽(第169场周赛)中的解題代碼
將 每個 數字轉換成十進位相加 如下:
以 "SEND"+"MORE"="MONEY" 為例:
  SEND=1000*S+100*E+10*N+D
  MORE=1000*M+100*O+10*R+E
  MONEY=10000*M+1000*O+100*N+10*E+Y
而 SEND+MORE=MONEY 可轉換成 SEND+MORE-MONEY=0
將每個數字轉換成十進位後, 再整理後可得 1000*S+91*E-90*N+D-9000*M-900*O+10*R+Y=0
之後再用回溯法求其是否有解

感謝 holiday 提醒，已更新避開開頭字母為 0 的狀況。

![a001.PNG](https://pic.leetcode-cn.com/d25f74f578526b76a1376ada22c545fd9fc41a3ee685745140d6a09960fd4759-a001.PNG)

### 代码

```java
class Solution {
    boolean fndAns(Map<Character,Integer> hm, List<Character> chAL, Set<Character> hS, boolean[] vstd, int sum){
        if(chAL.isEmpty()) return sum==0;//若所有字母皆有對應,則比對總和是否為0
        Character ch=chAL.remove(0);//回溯取出
        for(int ix=0;ix<10;ix++){
            if(vstd[ix]) continue;
            if(ix==0 && hS.contains(ch)) continue;//開頭字母避開0
            vstd[ix]=true;//回溯取出
            sum+=hm.get(ch)*ix;//回溯加上
            if(fndAns(hm,chAL,hS,vstd,sum)) return true;
            sum-=hm.get(ch)*ix;//回溯減回
            vstd[ix]=false;//回溯存回
        }
        chAL.add(0,ch);//回溯存回
        return false;
    }
    public boolean isSolvable(String[] words, String result) {
        Map<Character,Integer> hm=new HashMap<>();//使用到的字母,和其對應的十進位數目
        Set<Character> hS=new HashSet<>();//存放開頭字母, 以避開0
        for(String wd:words){
            char[] chs=wd.toCharArray();
            for(int ix=0;ix<chs.length;ix++){
                char ch=chs[ix];
                hm.put(ch,hm.getOrDefault(ch,0)+(int)Math.pow(10,chs.length-1-ix));//將字母轉成十進位
            }
        }
        char[] chs=result.toCharArray();
        for(int ix=0;ix<chs.length;ix++){
            char ch=chs[ix];
            hm.put(ch,hm.getOrDefault(ch,0)-(int)Math.pow(10,chs.length-1-ix));//wd為正, result 為負
        }
        List<Character> chAL=new ArrayList<>(hm.keySet());//列出此次用到的字母
        return fndAns(hm,chAL,hS,new boolean[10],0);
    }
}
```