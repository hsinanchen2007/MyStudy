```
class Solution {
    public List<Integer> partitionLabels(String S) {
        int len = S.length();
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();  //记录每一个字符的最后位置
        char c = 'a';
        for(int i = 0; i<len; i++){
            c = S.charAt(i);
            map.put(c, i);
        }
        //再遍历一边，将同一个字母划分为一段
        List<Integer> list = new ArrayList<Integer>();
        int max = -1;
        while(true){
            int index = max + 1;
            max = map.get(S.charAt(index));
            for(int i = index; i<=max; i++){
                c = S.charAt(i);
                if(map.get(c) > max){
                    max = map.get(c);
                 }
            }
            list.add(max - index + 1);
            if(max == len - 1){
                break;
            }
        }
        return list;
    }
}