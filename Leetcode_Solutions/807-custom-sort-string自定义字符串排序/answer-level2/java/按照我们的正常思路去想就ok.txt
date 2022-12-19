其实这道题最让人费解的就是题目到底要求怎么做
举个例子 S = "abc", T = "cccxaabbbbbbyz"
其中abc出现了，那么在T中的排序就需要按照a,b,c来排序，但是T中有重复，所以排序就成了aabbbbbbccc，至于xyz，放在最后面就行了，顺序可以随便改，比如xzy, yzx
所以思路就很明确了，我的思路整体如下：
(1)利用T中所有的字母都是小写字母的特性，利用int[26]的数组来存放相应的字母数量;
(2)根据S中字母出现的顺序，找到T中该字母对应的数量，然后全部放入我们的字符串，每次操作都将该字母的数量减1;
(3)因为所有和S有关的字母已经全部变为0，所有我们只需要再进行一次遍历，将T数组中对应的剩余字母全部加入字符串中;
代码如下:


```
    public String customSortString(String S, String T) {
        int[] charT = new int[26];

        for(char t : T.toCharArray()){
            charT[t - 'a']++;
        }

        StringBuilder res = new StringBuilder();
        for(char c : S.toCharArray()){
            int i = c - 'a';
            while(charT[i] > 0){
                res.append(c);
                charT[i]--;
            }
        }

        for(int i = 0; i < 26; i++){
            char c = (char)(i + 'a');
            while(charT[i] > 0){
                res.append(c);
                charT[i]--;
            }
        }

        return res.toString();
    }
```
