这题第一眼就觉得应该用哈希表加双向链表的结构，原本想自己实现来着，但感觉有点麻烦，，，果断放弃。
还好万能的Collection已经实现了这个结构，就是LinkedHashMap。先放张图给大家感受下它的结构：
![image.png](https://pic.leetcode-cn.com/b889060915aa174c38b74a50ea1bbb80572b7f65f5b7191028a8ef2c475ee42d-image.png)
然后这里有个我感觉写的还蛮好的博客，大家可以学习一下[图解LinkedHashMap原理](https://www.jianshu.com/p/8f4f58b4b8ab)
之所以使用LinkedHashMap是因为它内部会按插入顺序或访问顺序排序，这样当处理完String后，可以直接使用iterator（迭代器）遍历，一旦找到了满足要求的字符，返回即可。
代码如下（但效率属实一般，可最重要的是学习了LinkedHashMap鸭~吼吼吼）：
```
class Solution {
    public char firstUniqChar(String s) {
        if(s.isEmpty()) return ' ';
        //Map<Character,Boolean> map = new LinkedHashMap<Character,Boolean>(32,0.9f,true);
        Map<Character,Boolean> map = new LinkedHashMap<Character,Boolean>();
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(map.containsKey(c)){
                map.put(c,false);   //标记false表出现过该字符
            }else{
                map.put(c,true);    //标记true表该字符第一次出现
            }
        }
        Iterator<Entry<Character,Boolean>> it = map.entrySet().iterator();
        while(it.hasNext()){
            Entry<Character,Boolean> next = it.next();
            if(next.getValue()) return next.getKey();
        }
        return ' ';

    }
}
```
