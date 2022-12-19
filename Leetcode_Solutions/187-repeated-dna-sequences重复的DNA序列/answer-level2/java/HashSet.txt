// 创建两个hash，一个用于存 10个数组的清单
// 另外一个进行比较，如果再次出现，在存入

class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Set<String> find = new HashSet<>(); //如果再次出现，在存入
        Set<String> used = new HashSet<>(); //用于存 10个数组的清单
        
        for (int i = 0; i <= (s.length() - 10); i++) {
            String str1 = s.substring(i, i + 10);
            if (used.contains(str1)) {
                find.add(str1);
            } else {
                used.add(str1);
            }            
        }
        return new ArrayList<>(find);        
    }
}