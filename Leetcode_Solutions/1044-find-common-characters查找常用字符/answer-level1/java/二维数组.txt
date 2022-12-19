为每一个String创建一个char数组记录26个小写字母出现次数
然后纵向从a到z取得每个字母出现的最小次数，加入到结果中
```
class Solution {
    public List<String> commonChars(String[] A) {
        List<String> list =new ArrayList<String>();
        char[][] chars = new char[A.length][26];
        for(int i = 0;i <A.length;i++){
            for(int j = 0;j < A[i].length();j++){
                chars[i][A[i].charAt(j)-'a'] += 1;
            }
        }
        for(int i = 0;i < 26;i++){
            int min = Integer.MAX_VALUE;
            for(int j = 0; j < A.length;j++){
                if(chars[j][i]<min){
                    min = chars[j][i];
                }
            }
            for(int t = 0;t < min;t++){
                list.add(String.valueOf((char)('a'+i)));
            }
        }
        return list;
    }
}
```