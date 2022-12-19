### 解题思路
第一次完完全全坚持下来写出来的，更多的是看评论大佬理解精华和代码，
小白刚接触算法，只是知道dfs、动态规划、链表等等，但还不怎么会用，
基本看到很多题上来都是暴力算法，包括这道题也是，看了评论才知道哈希表怎么用。
好好努力，希望自己慢慢追上你们这些牛逼的大佬！

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int sum = 0;
        for(int i=0;i<words.length;i++){
            int count = 0;
            char a[] = words[i].toCharArray();
            char b[] = chars.toCharArray();
            for(int k=0;k<a.length;k++){
               for(int j =0;j<b.length;j++){
                 if(a[k]==b[j]){
                     count++;
                     b[j]=0;
                    j=b.length;
                 }
                  
             }
              if(count==a.length)
                  {
                      sum+=count;
                  }
            }
         }
        return sum;
    }
}
```