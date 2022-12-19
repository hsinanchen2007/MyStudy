class Solution {  
    public boolean canConstruct(String ransomNote, String magazine) {
        char[] ra = ransomNote.toCharArray();
        char[] ma = magazine.toCharArray();
        List<Character> list = new ArrayList<>();
        for(int i=0;i<ma.length;i++){
            list.add(ma[i]);  //将magazine的元素全部放入list中
        }
        for(int j=0;j<ra.length;j++){  //遍历ransomNote
            if(list.contains(ra[j])){  //如果ransomNote的元素属于list中的元素
                list.remove(list.indexOf(ra[j]));    //删除list当中与之相同的、第一次出现位置的元素
            }else{
                return false;  //如果ransomNote的元素不属于list中的元素，直接返回false
            }
        }
        return true; //否则返回true
    }
}