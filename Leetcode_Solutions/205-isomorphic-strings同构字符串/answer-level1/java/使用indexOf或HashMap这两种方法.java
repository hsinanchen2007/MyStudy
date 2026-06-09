1，使用HashMap
key为字符，value为出现的index。通过查找HashMap中的key，判断s是否有相同的字符，若有，则t在相同的位置也要有；若没有，t在相同的位置也不能有
2，使用indexOf
思路同上，只是通过indexOf判断相同字符出现的位置。注意，该位置不能与当前字符相同。

这两种方法性能差距不大，估计是字符长度比较小的原因。HashMap属于空间换时间。

class Solution {
    /*
    public boolean isIsomorphic(String s, String t) {
        if(s==null || t==null) {
            return false;
        }
        
        //使用HashMap存储s和t,用于检索
        //这里key是String,因为String实现了equals和hasCode方法,所以内容一致时,作为key值是相等的,并且可以
        Map<String,Integer> sCharMap = new HashMap<String,Integer>();
        Map<String,Integer> tCharMap = new HashMap<String,Integer>();
        for(int i=0;i<s.length();i++) {
            if(sCharMap.get(s.substring(i,i+1))!=null) {
                //s中有重复字符出现,检查t
                if(t.charAt(i)!=t.charAt(sCharMap.get(s.substring(i,i+1)))) {
                    return false;
                }
            }else {
                //System.out.print("key:" + t.substring(i,i+1) + " ,value: " + tCharMap.get(t.substring(i,i+1)));
                //s中没有重复字符出现,也要检查t
                if(tCharMap.get(t.substring(i,i+1))!=null) {
                    return false;
                }
            }
            sCharMap.put(s.substring(i,i+1),new Integer(i));            
            tCharMap.put(t.substring(i,i+1),new Integer(i));            
        }
        
        Set<String> keys = tCharMap.keySet();
        for (String key : keys) {
            Integer value = tCharMap.get(key);
            System.out.println(key+"---"+value);
            System.out.println('\n');
        }
        
        return true;
    }
    */
    
    //这里用String自身的查找功能实现
    public boolean isIsomorphic(String s, String t) {
        if(s==null || t==null) {
            return false;
        }
        
        for(int i=0;i<s.length();i++) {
            if(s.indexOf(s.substring(i,i+1))!=i) {
                //s找到了相同的,t也得在相同位置有重复
                if(t.indexOf(t.substring(i,i+1))!=s.indexOf(s.substring(i,i+1))) {
                    return false;
                }
            }else {
                //s没找到相同的,t也不能有
                if(t.indexOf(t.substring(i,i+1))!=i) {
                    return false;
                }
            }
        }

        return true;
    }
}