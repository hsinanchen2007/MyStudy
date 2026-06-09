### 解题思路
数据结构：字母树
思路：将单词word倒序插入
        如果没有分裂，说明当前word是之前某一个word的后缀，进入下一个循环
        如果发生分裂
            如果这是第一次分裂，即当前树节点的count为0，说明之前某一个word是当前word的后缀，count减去word走过的字母个数j，由于当前word和之前某一个word共用一个'#'，所以多减去1
            如果这已经分裂过了，即当前树节点的count大于0，说明两种情况，第一种情况是之前没有任何word是该word的后缀，只是之前有word和该word尾部相同而已，但是该word仍然可以是一个独立的单词，所以count+=word.length()+1，第二种情况是之前有word是该word的后缀，但是在第一次分裂已经被减去，所以该单词仍然可以看做一个独立的单词，还是count+=word.length()+1
### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        LetterTreeNode root = new LetterTreeNode();
        LetterTreeNode curr = root;
        int count = 0;
        boolean isSplit = false;
        for(String word: words) {
            for(int i=word.length()-1,j=1; i>=0; i--,j++) {
                char c = word.charAt(i);
                if(curr.childrens[c-'a'] != null) {
                    curr = curr.childrens[c-'a'];
                    if(i>0 && curr.count==0)
                        count -= j+1;
                }
                else {
                    isSplit = true;
                    curr.childrens[c-'a'] = new LetterTreeNode();
                    curr.count++;
                    curr = curr.childrens[c-'a'];
                }
            }
            if(isSplit)
                count += word.length()+1;
            isSplit = false;
            curr = root;
        }
        return count;
    }
}

class LetterTreeNode {
    LetterTreeNode[] childrens;
    int count=0;

    LetterTreeNode() {
        childrens = new LetterTreeNode[26];
    }
}
```