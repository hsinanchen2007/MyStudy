### 解题思路
先用快速排序排序一下，大的单词在前头,然后contain就好
注意me 和 mean！
### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        StringBuilder res=new StringBuilder("");
        int count=0;
        wordsSort(words,0,words.length-1);
        for (int i = 0; i < words.length; i++) {
            if(!res.toString().contains(words[i]+"#")){
                res.append(words[i]).append("#");
            }
        }
        System.out.println(res.toString());
        return res.length();
    }
    private void wordsSort(String[] words,int l,int r){
        if (l<r){
            int left=l;
            int right=r;
            String x = words[left];
            while(left<right){
                while (left<right&&words[right].length()<=x.length()){right--;}
                if (left<right){
                    words[left]=words[right];
                    left++;
                }
                while (left<right&&words[left].length()>x.length()){left++;}
                if (left<right){
                    words[right]=words[left];
                    right--;
                }
            }
            words[left]=x;
            wordsSort(words,l,left-1);
            wordsSort(words,left+1,r);
        }
    }
}
```