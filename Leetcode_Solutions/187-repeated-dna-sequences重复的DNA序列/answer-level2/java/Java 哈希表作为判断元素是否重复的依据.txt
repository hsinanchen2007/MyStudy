


# class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        String tmp = "";
        int index = 0;
        List<String>l = new ArrayList<String>();
        Set<String>set = new HashSet<String>();
        int i= 0;
        while(i<=s.length()-10){
            tmp = s.substring(i,i+10);
            if(set.contains(tmp) && (!l.contains(tmp))){
                l.add(tmp);
            }
            else{set.add(tmp);}
            i++;
        }
        return l;
    }
}

第一次用传统的方法indexOf10个10个遍历结果果断超时，想了想直接用HashSet做判断依据看看10个字符串是否重复，重复的加入到List中
，(!l.contains(10个字符串)防止相同的字符串加两次，list.contains这个操作比起哈希表contains不是一点点的费时，但是对付那种单个char出现N次的情况最简单的思路就是它了