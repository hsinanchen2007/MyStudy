遍历字符串中每一个字符，将其插入到已生成的字符串，例如qwe，先生成q，然后遍历到w时，插入到q中，得到qw和wq，再遍历到e时，插入到qw和wq中得eqw，qew，qwe和ewq，weq，wqe

class Solution {
    public String[] permutation(String S) {
        Queue<String> queue = new LinkedList<>();
        for(char ch:S.toCharArray()){
            if(queue.isEmpty()){
                queue.offer(String.valueOf(ch));
            }else{
                int len = queue.size();
                for(int i = 0; i < len; ++i){
                    StringBuilder str = new StringBuilder(queue.poll());
                    for(int j = 0; j <= str.length(); ++j){
                        StringBuilder strNew = new StringBuilder(str);
                        strNew.insert(j, ch);
                        queue.offer(strNew.toString());
                    }
                }
            }
        }
        return queue.toArray(new String[0]);
    }
}

