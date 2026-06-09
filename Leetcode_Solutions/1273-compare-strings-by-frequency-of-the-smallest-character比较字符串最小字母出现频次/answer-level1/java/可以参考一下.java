```
class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int i,n1 = queries.length,n2 = words.length;
        
        int[] a = new int[n1];
        int[] aa = new int[n1];
        int[] b = new int[n2];
        for(i = 0;i < n1;i++){
            a[i] = fin(queries[i]);
        }
        for(i = 0;i < n2;i++){
            b[i] = fin(words[i]);
        }
        Arrays.sort(b);
        int j;
        for(i = 0;i < n1;i++){
            for(j = 0;j < n2;j++){//查找比queries中更小的最小字母个数
                if(a[i] < b[j]){
                    aa[i] = n2 - j;
                    break;
                }
            }
        }
        return aa;
    }
    public int fin(String s){//找到字符串中最小字符的个数
        char[] ch = s.toCharArray();
        Arrays.sort(ch);
        int coun = 0;
        int i;
        for(i = 0;i < s.length();i++){
            if(ch[i] == ch[0])
                coun++;
        }
        return coun;
    }
}
```
