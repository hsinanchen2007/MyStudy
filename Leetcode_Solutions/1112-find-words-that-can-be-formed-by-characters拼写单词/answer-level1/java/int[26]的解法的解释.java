### 解题思路

都是自己明白，关键的地方却没说，没有给不明白的人讲明白。能给小白说明白才是真的厉害。

我最开始就不明白在这个ASCII码是什么操作。后来才想明白了。

首先解题思路是：先把word和chars有哪些字母，字母的数量对应存一遍。在word中任取一个字母，在chars中都有。就能拼成。即：word中每一个字母的数量，都小于此字母在chars中的数量。chars中没有此字母的话，chars中就是有0个这个字母。

比如对于word数组：{hello,cat} 和cahrs数组：{h,e,l,l,o,b,h} word数组中的单词hello，每个字母w,o,r,d都只有一个，这五个字母在chars数组里都有，且chars里的这四个字母，每一个字母的个数都大于等于word里的。就肯定能组成。

然后int[26]是怎么回事：

int[26] 这个数组的意义就是：位置代表字母。位置上存的数，代表这个字母的个数。即：第一位，int[0]代表字母a出现的次数。第二位，int[b]代表字母b出现的次数。

所以int[0]就是a的个数。也就是说，在数组中有￥个字母&，即字母&出现过￥次，则有：int[x] = ￥ 。 x=&-’a‘。

写给我自己看的。终于明白了。
### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] cha = new int[26];
        for(char cc : chars.toCharArray()){
            cha[cc-'a'] ++;
        }
        int ans = 0;
        a:for(String word:words){
            int[] chaW = new int[26];
            for(char ww:word.toCharArray()){
                chaW[ww-'a']++;
            }
            for(int i = 0;i<26;i++){
                if(chaW[i]>cha[i]){
                    continue a;
                }
            }
             ans+=word.length();
        }
        return ans;
    }
}
```