利用优先队列和map存储包含的字符排序，可以扩展到N个字符和最大N次
每次取优先队列的首个字符判断结果集中是否包含连续出现两次的情况，如果出现则取下一个字符

JAVA 3ms

```
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        HashMap<Character,Integer> map = new HashMap();
        map.put('a',a);
        map.put('b',b);
        map.put('c',c);
        PriorityQueue<Character> que = new PriorityQueue<Character>((ac,bc) -> (map.get(bc) - map.get(ac)));
        que.offer('a');
        que.offer('b');
        que.offer('c');
        StringBuffer sb = new StringBuffer();
        while(true){
            char cc = que.poll();
            if(map.get(cc)>0){
                if(sb.length()>=2 && (sb.charAt(sb.length()-1) == cc && sb.charAt(sb.length()-2) == cc)){
                    char bc = que.poll();
                    if(map.get(bc)>0){
                        sb.append(bc);
                        map.put(bc,map.get(bc)-1);
                        que.offer(bc);
                        que.offer(cc);
                    }else{
                        break;
                    }
                }else{
                    sb.append(cc);
                    map.put(cc,map.get(cc)-1);
                    que.offer(cc);
                }
            }else{
                break;
            }
        }

        return sb.toString();

    }
}
```
