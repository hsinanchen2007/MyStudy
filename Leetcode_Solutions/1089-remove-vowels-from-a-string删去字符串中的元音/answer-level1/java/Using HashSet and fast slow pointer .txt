Time Complex:O(N)-->一次遍历  
Space Complex:O(N)-->把字符串转换成characterArray
首先把元音字符加入到HashSet中，然后利用快慢指针一次遍历原来的字符串；
如果是非元音字母，copy到前面；
遍历结束之后检查slow指针（当全部是元音字母的时候返回空字符串）；
返回Character array 的[0,slow] 字符组成的字符串。

优化方法：如果需要减少内存可以把HashSet去除，使用if条件语句进行判断，但是这样的代码扩展性会变差。
```
class Solution {
    public String removeVowels(String S) {
        //Corner case 
        if(S==null || S.length()==0){
            return S;
        }
        char[] array=S.toCharArray();
        HashSet<Character> set=new HashSet<Character>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
        int slow=-1;
        for(int fast=0;fast<array.length;fast++){
            if(!set.contains(array[fast])){
                //copy the fast to ++slow
                array[++slow]=array[fast];
            }
            //else do nothing
        }
        //Post processing 
        if(slow==-1){
            return new String("");
        }
        return new String(array,0,slow+1);
    }
}
```
