```
class Solution {
    //通过字母的ASCII码作为数组的索引，开辟空间的大小为26+6+26=58：26个大写字母，26个小写字母，
    //还有中间的6个非字母  A~Z[65~90]  非字母[91~96]  a~z[97~122]
    
    //需要注意的点：
    //1.遍历字符串的时候尽量用s.toCharArray(),会比s.charAt()快一些
    //2.用干净的数组比HashMap要快至少50ms
    public String minWindow(String s, String t) {
        int[] cs = new int[58];
        int[] ct = new int[58];
        
        List<Integer> indexs = new ArrayList<>();
        
        //统计t中每个字符的出现次数
        for(char c : t.toCharArray()) {
            ct[c - 'A']++;
        }
        
        //对比的时候只需要对比在t种出现的字符就可以了
        for(int i = 0; i < ct.length; i++) {
            if(ct[i] > 0) {
                indexs.add(i);
            }
        } 
        String ans = "";
        char[] chs = s.toCharArray();
        for(int i = 0,j = 0 ; j < s.length(); j++) {//以当前字符结尾
            
            cs[chs[j] - 'A']++;
            while(i < j) {//看看i是否能向后移，尽量将窗口缩小
                int index = chs[i] - 'A';
                if(cs[index] > ct[index]) {//向后移的条件，即使没有你依然可以满足
                    i++;
                    cs[index]--;
                }else {
                    break;
                }
            }
            if(check(indexs,cs,ct)) {
                if(ans == "" || j - i + 1 < ans.length()) {
                    ans = s.substring(i,j + 1);
                }
            }  
        }
        return ans;
    }
    
    public boolean check(List<Integer> indexs,int[] cs,int[] ct) {  
        for(int i : indexs) {
            if(cs[i] < ct[i]) {
                return false;
            }
        }
        return true;
    }
}
```
