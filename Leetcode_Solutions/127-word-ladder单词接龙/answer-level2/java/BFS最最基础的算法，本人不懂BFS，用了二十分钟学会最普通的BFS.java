### 解题思路
看注释吧，看完就会BFS了，BFS和先入先出的队列是分不开的。

### 代码

```java
//BFS
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if(!wordList.contains(endWord)){
            return 0;
        }
        //已经访问过的结点
        Set<String> visited = new HashSet<>();
        //当前要访问结点存进的队列
        Queue<String> queue =new LinkedList<>();
        queue.offer(beginWord);
        visited.add(beginWord);
        int count=0;
        while(queue.size()>0){
            int size=queue.size();
            ++count;
            //在当前要访问结点存进的队列里开始逐个检验，并且把结点的下一层放进队列里，BFS
            for(int i=0;i<size;i++){
                //每次都是最新要比较的单词 start
                String start=queue.poll();
                //因为有的单词已经遍历过，有的单词不满足转换会跳过，所以整个wordList遍历一次
                for(String s:wordList){
                    //已遍历过，跳过看下一个单词
                    if(visited.contains(s)){
                        continue;
                    }
                    //不能转换一个字母变成这个单词的，也跳过
                    if(!canConvert(start,s)){
                        continue;
                    }
                    //没遍历过，又能转换的，当是最后转换成endWord时
                    if(s.equals(endWord)){
                        return ++count;
                    }
                    //没遍历过，又能转换的，还没到最后的end的
                    //存进visited，放入队列之后搜索
                    visited.add(s);
                    queue.offer(s);
                }
            }
        }
        return 0;
    }
    public boolean canConvert(String s1,String s2){
        if(s1.length()!=s2.length()){
            return false;
        }
        int count=0;
        for(int i=0;i<s1.length();i++){
            if(s1.charAt(i)!=s2.charAt(i)){
                count++;
                if(count>1){
                    return false;
                }
            }
        }
        return true;
    }
}



```