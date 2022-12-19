思路：
1.先保存每个字符在字符串中最右的下标
2.遍历字符串，假如当前字符最右坐标最大，就更新右区间，直到达到右区间，就是一个字母区间
3.保存区间长度，更新左区间(左区间目的仅是方便求区间长度)


```
class Solution {
    public List<Integer> partitionLabels(String S) {
        List<Integer> list = new ArrayList<>();
        int[] last = new int[26];
        for (int i = 0; i < S.length(); i++) {
            last[S.charAt(i) - 'a'] = i;
        }
        int preRight = -1,max_index = 0;
        for(int i=0;i<S.length();i++){
            int index = last[S.charAt(i)-'a'];
            if(index>max_index){
                max_index = index;
            }
            if(i==max_index){
                list.add(max_index-preRight);
                preRight = max_index;
            }
        }
        return list;
    }
}
```
