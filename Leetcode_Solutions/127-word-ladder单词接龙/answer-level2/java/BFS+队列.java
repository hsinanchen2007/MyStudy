执行结果：
通过
显示详情
执行用时 :
595 ms
, 在所有 Java 提交中击败了
21.87%
的用户
内存消耗 :
42.8 MB
, 在所有 Java 提交中击败了
55.93%
的用户
```
class Solution {
    
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        int res=1;
        Set<String> set = new HashSet<>(wordList);
        if(!set.contains(endWord))return 0;
        LinkedList<String> ll = new LinkedList<>();
        ll.add(beginWord);
        set.remove(beginWord);
        while(!ll.isEmpty()){
            res++;
            int size=ll.size();
            for(int i=0; i<size; i++){
                String s = ll.pop();
                Iterator<String> it = set.iterator();
                while(it.hasNext()){
                    String next = it.next();
                    if(adj(s,next)){
                        it.remove();
                        if(next.equals(endWord)){
                            return res;
                        }else{
                            ll.add(next);
                        }
                    }
                }
            }
        }
        return 0;
        
    }
    
    private boolean adj(String a,String b){
        int len = a.length()-1;
        int diff=0;
        while(len>=0){
            if(a.charAt(len)!=b.charAt(len)){
                diff++;
                if(diff>1)return false;
            }
            len--;
        }
        return true;
    }
}
```
